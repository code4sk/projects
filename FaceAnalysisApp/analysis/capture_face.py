import os
import cv2
import numpy as np
from django.http import HttpResponse
from PIL import Image
from analysis.models import Camera
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

matplotlib.use('agg')
import matplotlib.pyplot as plt
import numpy as np
# from sklearn.externals import joblib
from sklearn.neighbors import KNeighborsClassifier
from keras.models import load_model
import keras
from analysis.inception_res_net1 import InceptionResNetV1
from analysis.models import Pic, Person

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

from django.core.files import File

K.clear_session()

face = None
frame = None
x = 0
y = 0
w = 0
h = 0
faces = []


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

    def get_frame(self, process_this_frame, video_capture):
        # ret, frame = video_capture.read()
        global frame, x, y, w, h, faces
        frame = self.file.read()

        gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

        faces = self.faceCascade.detectMultiScale(
            gray,
            scaleFactor=1.1,
            minNeighbors=5,
            minSize=(30, 30),
            flags=cv2.CASCADE_SCALE_IMAGE
        )

        # Draw a rectangle around the faces
        for (x, y, w, h) in faces:
            cv2.rectangle(frame, (x, y), (x + w, y + h), (0, 255, 0), 2)

        # Display the resulting frame
        # cv2.imshow('Video', frame)

        frame = cv2.resize(frame, (640, 480))
        ret, imgencode = cv2.imencode('.jpg', frame)
        return imgencode.tobytes()


def gen(camera):
    global i, frame
    i = 0
    video_capture = None
    while True:
        i += 1
        if i % 10 == 0:
            process_this_frame = True
        else:
            process_this_frame = False
        frame = camera.get_frame(process_this_frame, video_capture)
        yield (b'--frame\r\n'
               b'Content-Type: image/jpeg\r\n\r\n' + frame + b'\r\n\r\n')


def capture_face(request, camera_id=0):
    # return the response generated along with the specific media
    # type (mime type)
    # print(camera_url)
    # camera_url = "http://192.168.1.4:8080/video"
    # camera_url = 0
    # camera_url = "/home/mudit/Downloads/VID_20200123_221509.mp4"
    print(camera_id)
    try:
        camera_url = Camera.objects.get(id=camera_id).url
    except Exception as e:
        camera_url = 0
    if camera_url == "0":
        camera_url = int(camera_url)
    return StreamingHttpResponse(gen(VideoCamera(camera_url, request)), content_type='multipart/x-mixed-replace; boundary=frame')


def save_face(request, person_id):
    if len(faces) != 1:
        return HttpResponse('wrong number of faces')
    p = Person.objects.get(person_id=person_id)
    num = len(Pic.objects.filter(person=p))
    num += 1
    path = "./media/faces/{}/face-{}.jpg".format(person_id, num)
    temp_path = "./media/faces/{}/face-{}-temp.jpg".format(person_id, num)
    print(path)
    crop_img = frame[y: y + h, x: x + w]  # Crop from x, y, w, h -> 100, 200, 300, 400
    cv2.imwrite(temp_path, crop_img)
    pic = Pic.objects.create(person=p)
    # pic.image.save(
    #     "face-{}.jpg".format(num),
    #     File(open(path, 'rb'))
    # )
    # pic.image = path
    from django.core.files.base import ContentFile

    with open(temp_path, 'rb') as f:
        data = f.read()

    # obj.image is the ImageField
    pic.image.save("face-{}.jpg".format(num), ContentFile(data))
    pic.save()
    os.remove(temp_path)
    print(pic)
    return HttpResponse('done')

