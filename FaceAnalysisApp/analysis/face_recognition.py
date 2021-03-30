import os
import cv2
import numpy as np
from django.http import HttpResponse
from PIL import Image
from sklearn.preprocessing import LabelEncoder
from sklearn.preprocessing import Normalizer
from sklearn.svm import SVC
import tensorflow as tf
import pickle
from tensorflow.keras import backend as K
from tensorflow.keras import models, layers
from tensorflow.keras.utils import to_categorical
# import matplotlib.pyplot as plt
import matplotlib
from analysis.models import Camera
matplotlib.use('agg')
import matplotlib.pyplot as plt
import numpy as np
# from sklearn.externals import joblib
from sklearn.neighbors import KNeighborsClassifier
from keras.models import load_model
import keras
from analysis.inception_res_net1 import InceptionResNetV1

import dlib
from imutils import face_utils
import imutils
from imutils.video import WebcamVideoStream
from keras.models import load_model
from keras import backend as K
from sklearn import neighbors
from django.http import StreamingHttpResponse

import tensorflow as tf
import joblib
import threading

K.clear_session()

face = None


class FaceAligner:
    def __init__(self, predictor, desiredLeftEye=(0.35, 0.35),
                 desiredFaceWidth=256, desiredFaceHeight=None):
        self.predictor = predictor
        self.desiredLeftEye = desiredLeftEye
        self.desiredFaceWidth = desiredFaceWidth
        self.desiredFaceHeight = desiredFaceHeight
        if self.desiredFaceHeight is None:
            self.desiredFaceHeight = self.desiredFaceWidth

    def align(self, image, gray, rect):
        shape = self.predictor(gray, rect)
        shape = face_utils.shape_to_np(shape)
        if (len(shape) == 68):
            (lStart, lEnd) = face_utils.FACIAL_LANDMARKS_68_IDXS["left_eye"]
            (rStart, rEnd) = face_utils.FACIAL_LANDMARKS_68_IDXS["right_eye"]
        else:
            (lStart, lEnd) = face_utils.FACIAL_LANDMARKS_5_IDXS["left_eye"]
            (rStart, rEnd) = face_utils.FACIAL_LANDMARKS_5_IDXS["right_eye"]
        leftEyePts = shape[lStart:lEnd]
        rightEyePts = shape[rStart:rEnd]
        leftEyeCenter = leftEyePts.mean(axis=0).astype("int")
        rightEyeCenter = rightEyePts.mean(axis=0).astype("int")
        dY = rightEyeCenter[1] - leftEyeCenter[1]
        dX = rightEyeCenter[0] - leftEyeCenter[0]
        angle = np.degrees(np.arctan2(dY, dX)) - 180
        return angle


class VideoCamera(object):
    def __init__(self, camera_url, request):
        # Using OpenCV to capture from device 0. If you have trouble capturing
        # from a webcam, comment the line below out and use a video file
        # instead.
        print(camera_url)
        self.request = request
        try:
            self.file = WebcamVideoStream(src=camera_url).start()
        except:
            self.file = WebcamVideoStream(src=0).start()
        K.clear_session()
        self.cascPath = 'analysis/haarcascade_frontalface_dataset.xml'
        self.faceCascade = cv2.CascadeClassifier(self.cascPath)
        self.new_face_encodings = []
        self.new_face_names = []
        self.detector = dlib.get_frontal_face_detector()
        self.predictor_path = 'analysis/shape_predictor_68_face_landmarks.dat'
        self.predictor = dlib.shape_predictor(self.predictor_path)
        self.face = FaceAligner(self.predictor, desiredFaceWidth=600)

        self.face_locations = []
        self.face_encodings = []
        self.face_names = []

        print("#" * 80)
        self.modelFace = InceptionResNetV1()

        self.modelFace.load_weights('./analysis/facenet_keras.h5')
        self.in_encoder = Normalizer(norm='l2')
        self.classifier_path = './model.h5'
        self.label_map_path = './mapping.pkl'
        self.image_database = "./media/faces/"

    def create_classifier_data(self, image_database):
        new_face_encodings = []
        new_face_names = []
        for person in os.listdir(image_database):
            print(person)
            for filename in os.listdir(image_database + person):
                image = Image.open(os.path.join(image_database, person, filename))
                image = image.convert('RGB')
                pixels = np.asarray(image)
                image = image.resize((160, 160))
                face_array = np.asarray(image)
                face_pixels = face_array.astype('float32')
                mean, std = face_pixels.mean(), face_pixels.std()
                face_pixels = (face_pixels - mean) / std
                samples = np.expand_dims(face_pixels, axis=0)
                yhat = self.modelFace.predict(samples)
                new_face_encodings.append(yhat[0])
                # person = list(filename.split('.'))[0]
                new_face_names.append(person)
        known_face_encodings = new_face_encodings
        known_face_names = new_face_names
        known_face_encodings = np.asarray(known_face_encodings)
        trainy = np.asarray(known_face_names)

        trainX = self.in_encoder.transform(known_face_encodings)

        out_encoder = LabelEncoder()
        out_encoder.fit(known_face_names)
        trainy = out_encoder.transform(known_face_names)
        mapping = dict()
        for i in range(len(trainy)):
            mapping[trainy[i]] = known_face_names[i]

        print(mapping)
        return mapping, trainX, trainy

    def create_classifier(self, image_database):
        if not os.path.exists('model.h5'):
            mapping, trainX, trainy = create_classifier_data(image_database)
            classifier = models.Sequential()
            classifier.add(layers.Dense(64, activation='relu', input_shape=(128,)))
            classifier.add(layers.Dense(len(os.listdir(image_database)), activation='softmax'))
            classifier.compile(optimizer='Adam', loss='categorical_crossentropy', metrics=['accuracy'])
            train_labels = to_categorical(trainy)
            history = classifier.fit(trainX, train_labels, epochs=100, batch_size=64)
            classifier.save("model.h5")
            joblib.dump(mapping, "mapping.pkl")
            print("Training done!!!")
            return classifier, mapping
        else:
            try:
                classifier = tf.keras.models.load_model('./model.h5')
                mapping = joblib.load("./mapping.pkl")
            except Exception as E:
                print(E)
            return classifier, mapping

    def recog(self, frame):
        self.classifier, self.mapping = self.create_classifier(self.image_database)
        self.clf = self.classifier
        print(frame)
        frame = cv2.resize(frame, (1000, 1200))
        small_frame = cv2.resize(frame, (0, 0), fx=0.25, fy=0.25)
        rgb_small_frame = small_frame[:, :, ::-1]
        if True:
            gray = cv2.cvtColor(rgb_small_frame, cv2.COLOR_BGR2GRAY)
            face_locations = self.faceCascade.detectMultiScale(gray, minNeighbors=5, minSize=(30, 30),
                                                               flags=cv2.CASCADE_SCALE_IMAGE)
            face_encodings = []
            for (x, y, w, h) in face_locations:
                image = rgb_small_frame[y:y + h, x:x + w]
                image = cv2.resize(image, (160, 160))
                face_array = np.asarray(image)
                face_pixels = face_array.astype('float32')
                print(face_pixels.shape)
                mean, std = face_pixels.mean(), face_pixels.std()
                face_pixels = (face_pixels - mean) / std
                samples = np.expand_dims(face_pixels, axis=0)
                yhat = self.modelFace.predict(samples)
                print(yhat)
                face_encodings.append(yhat[0])

            face_encodings = np.asarray(face_encodings)

            if (face_encodings != []):
                if (len(list(face_encodings.shape)) == 1):
                    face_encodings = face_encodings.reshape(-1, 1)
                testX = self.in_encoder.transform(face_encodings)
                global face
                face_names = self.clf.predict(testX)
                yhat_test = []
                for i in face_names:
                    face = i
                    yhat_test.append(np.argmax(i))
                face_names = yhat_test
                print(face_names)
                self.request.faces = face_names

                # Display the results
                for (x, y, w, h), name in zip(face_locations, face_names):
                    x *= 4
                    y *= 4
                    w *= 4
                    h *= 4
                    font = cv2.FONT_HERSHEY_DUPLEX
                    display = str(self.mapping[name])
                    print(display)
                    face = display
                    cv2.rectangle(frame, (x, y), (x + w, y + h), (0, 0, 255), 1)
                    cv2.putText(frame, display, (x + w + 6, y + h - 6), font, 1.0, (255, 255, 255), 1)
            return frame

    def get_frame(self, process_this_frame):
        frame = self.file.read()
        frame = imutils.resize(frame, width=600)
        gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
        detect = self.detector(gray)
        if process_this_frame:
            if (len(detect) > 0):
                for det in detect:
                    # pass
                    # shape = self.predictor(gray, det)
                    # shape = face_utils.shape_to_np(shape)
                    # align = self.face.align(frame, gray, det)
                    # (x, y, w, h) = face_utils.rect_to_bb(det)
                    # t = threading.Thread(target=predict, args=(self.recog, frame,))

                    frame = self.recog(frame)
            else:
                global face
                face = "NO Face Detected"
                cv2.putText(frame, "NO FACE PRESENT", (20, 20), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 0, 255), 2)

        frame = cv2.resize(frame, (640, 480))
        ret, imgencode = cv2.imencode('.jpg', frame)
        return imgencode.tobytes()


def predict(recog, frame):
    frame = recog(frame)

def gen(camera):
    global i
    i = 0
    while True:
        i += 1
        if i % 10 == 0:
            process_this_frame = True
        else:
            process_this_frame = False
        frame = camera.get_frame(process_this_frame)
        yield (b'--frame\r\n'
               b'Content-Type: image/jpeg\r\n\r\n' + frame + b'\r\n\r\n')


def face_alignment_and_detection(request, camera_id=0):
    # return the response generated along with the specific media
    # type (mime type)
    # camera_url = "http://192.168.1.4:8080/video"
    # camera_url = "/home/mudit/Downloads/VID_20200123_221509.mp4"
    print(camera_id)

    try:
        camera_url = Camera.objects.get(id=camera_id).url
    except Exception as e:
        camera_url = 0
    if camera_url == "0":
        camera_url = int(camera_url)
    return StreamingHttpResponse(gen(VideoCamera(camera_url, request)), content_type='multipart/x-mixed-replace; boundary=frame')


def get_faces_names(request):
    global face
    return HttpResponse(str(face))
