from django.shortcuts import render, redirect
from django.http import HttpResponse, JsonResponse
from django.contrib.auth import authenticate, login, logout
from django.contrib import messages
import os
from .models import Pic, Person, Camera
import pyrebase
import cv2
from analysis.inception_res_net1 import InceptionResNetV1
from sklearn.preprocessing import LabelEncoder
from sklearn.preprocessing import Normalizer
import time
from datetime import datetime, timezone
import pytz
from django.views.generic import View
import os

from PIL import Image
from sklearn.preprocessing import LabelEncoder
from sklearn.preprocessing import Normalizer
from sklearn.svm import SVC
import tensorflow as tf
import pickle
from tensorflow.keras import backend as K
from tensorflow.keras import models, layers
from tensorflow.keras.utils import to_categorical
from .face_recognition import face_alignment_and_detection, get_faces_names

import numpy as np
# from sklearn.externals import joblib
import joblib
import json
import keras
from sklearn.neighbors import KNeighborsClassifier
from keras.models import load_model
import keras
from django.contrib.auth.decorators import login_required
from django.utils.decorators import method_decorator
from analysis.forms import CameraForm

config = {
    "apiKey": "AIzaSyCo5vPXR-z--PkCvtNWH8dSjprEIyBF3nU",
    "authDomain": "astute-alert-database.firebaseapp.com",
    "databaseURL": "https://astute-alert-database.firebaseio.com",
    "projectId": "astute-alert-database",
    "storageBucket": "astute-alert-database.appspot.com",
    "messagingSenderId": "465299113095",
    "appId": "1:465299113095:web:eae7003c2565770b4ae422",
    "measurementId": "G-JWBBQK57N7"
}

firebase = pyrebase.initialize_app(config)
fb_auth = firebase.auth()
db = firebase.database()
storage = firebase.storage()

K.clear_session()
cascPath = './analysis/haarcascade_frontalface_dataset.xml'
faceCascade = cv2.CascadeClassifier(cascPath)

cascPath = 'haarcascade_frontalface_dataset.xml'
# faceCascade = cv2.CascadeClassifier(cascPath)
image_database = "./media/faces/"
in_encoder = Normalizer(norm='l2')


def create_classifier_data(image_database):
    new_face_encodings = []
    new_face_names = []
    modelFace = InceptionResNetV1()
    modelFace.load_weights('./analysis/facenet_keras.h5')
    query_set = Person.objects.all()
    print (query_set.count())
    for person in Person.objects.all().values_list('person_id', flat=True):
        print(person)
        for pic in Pic.objects.filter(person__person_id=person):
            filename = pic.image.name.split('/')[-1]
            image = Image.open(os.path.join(image_database, person, filename))
            image = image.convert('RGB')
            pixels = np.asarray(image)
            image = image.resize((160, 160))
            face_array = np.asarray(image)
            face_array_list = face_array.tolist()

            # print(face_array)
            pic.encoding = json.dumps({'encoding': face_array_list})
            pic.save()
            face_pixels = face_array.astype('float32')
            mean, std = face_pixels.mean(), face_pixels.std()
            face_pixels = (face_pixels - mean) / std
            samples = np.expand_dims(face_pixels, axis=0)
            yhat = modelFace.predict(samples)
            new_face_encodings.append(yhat[0])
            # person = list(filename.split('.'))[0]
            new_face_names.append(person)
    known_face_encodings = new_face_encodings
    known_face_names = new_face_names
    known_face_encodings = np.asarray(known_face_encodings)
    trainy = np.asarray(known_face_names)

    trainX = in_encoder.transform(known_face_encodings)

    out_encoder = LabelEncoder()
    out_encoder.fit(known_face_names)
    trainy = out_encoder.transform(known_face_names)
    mapping = dict()
    for i in range(len(trainy)):
        mapping[trainy[i]] = known_face_names[i]

    print(mapping)
    return mapping, trainX, trainy


def create_classifier(image_database):
    query_set = Person.objects.all()
    mapping, trainX, trainy = create_classifier_data(image_database)
    classifier = models.Sequential()
    classifier.add(layers.Dense(64, activation='relu', input_shape=(128,)))
    classifier.add(layers.Dense(query_set.count(), activation='softmax'))
    classifier.compile(optimizer='Adam', loss='categorical_crossentropy', metrics=['accuracy'])
    train_labels = to_categorical(trainy)
    history = classifier.fit(trainX, train_labels, epochs=100, batch_size=64)
    classifier.save("model.h5")
    joblib.dump(mapping, "mapping.pkl")
    print("Training done!!!")
    return classifier, mapping


# @method_decorator(login_required, name='dispatch')
class Home(View):
    def get(self, request):
        return redirect('analysis:upload')


# @method_decorator(login_required, name='dispatch')
class Upload(View):
    def get(self, request):
        people = Person.objects.all()
        cameras = Camera.objects.all()
        print (people)
        return render(request, 'analysis/upload.html', {'people': people, 'cameras': cameras})

    def post(self, request):
        name = request.POST.get('name')
        people = Person.objects.all()
        cameras = Camera.objects.all()
        if Person.objects.filter(person_id=name).exists():
            return render(request, 'analysis/upload.html', {'people': people})
        if name == '':
            people = Person.objects.all()
            return render(request, 'analysis/upload.html', {'people': people})
        else:
            people = Person.objects.all()
            p = Person.objects.create(name=name)
            print(p)
            try:
                os.mkdir('./media/faces/{}'.format(name))
            except Exception as e:
                print(e)
            # classifier, mapping = create_classifier(image_database)
            return redirect('analysis:display-image', person_id= p.person_id)


# @method_decorator(login_required, name='dispatch')
class DisplayImage(View):
    def get(self, request, person_id):
        p = Person.objects.get(person_id=person_id)
        images = Pic.objects.filter(person=p)
        cameras = Camera.objects.all()
        return render(request, 'analysis/display-image.html', {'images': images, 'person_id': person_id,
                                                               'cameras': cameras})

    def post(self, request, person_id):
        # person_id = request.POST.get('person_id')
        p = Person.objects.get(person_id=person_id)
        for file in request.FILES.getlist('images'):
            print(file)
            pic = Pic.objects.create(person=p, image=file)
            print(pic)
        images = Pic.objects.filter(person__person_id=person_id)
        cameras = Camera.objects.all()
        return render(request, 'analysis/display-image.html', {'images': images, 'person_id': person_id,
                                                               'cameras': cameras})


# @method_decorator(login_required, name='dispatch')
class DeletePerson(View):
    def get(self, request, person_id):
        person = Person.objects.get(person_id=person_id)
        name = person.name
        for pic in person.pic_set.all():
            pic.image.delete(save=True)
        person.delete()
        try:
            os.rmdir('./media/faces/{}'.format(name))
        except Exception as e:
            print(e)
        people = Person.objects.all()
        return redirect('analysis:upload')


# @method_decorator(login_required, name='dispatch')
class Train(View):
    def get(self, request):
        classifier, mapping = create_classifier(image_database)
        return HttpResponse('done')


# @method_decorator(login_required, name='dispatch')
class FaceAnalysis(View):
    def get(self, request):
        camera_id = request.GET.get('camera_id', 0)
        return render(request, 'analysis/face-analysis.html', {'camera_id': camera_id})


# @login_required
def face_recognition(request, camera_id):
    # camera_url = CameraUrl.objects.filter().get(name=cam_obj).url
    return face_alignment_and_detection(request, camera_id)


# @login_required
def get_faces(request):
    return get_faces_names(request)


# @method_decorator(login_required, name='dispatch')
class CreateDataset(View):
    def get(self, request, person_id):
        camera_id = request.GET.get('camera_id', 0)
        return render(request, 'analysis/create-dataset.html', {'person_id': person_id, 'camera_id': camera_id})


# @method_decorator(login_required, name='dispatch')
class DeleteImage(View):
    def get(self, request, id):
        p = Pic.objects.get(id=id)
        person_id = p.person.person_id
        p.image.delete(save=True)
        print(p.delete())
        return redirect('analysis:display-image', person_id=person_id)


class CreateCamera(View):
    def get(self, request):
        form = CameraForm()
        return render(request, 'analysis/create-camera.html', {'form': form})

    def post(self, request):
        form = CameraForm(request.POST)
        if form.is_valid():
            form.save()
            return redirect('analysis:upload')
        else:
            return render(request, 'analysis/create-camera.html', {'form': form})
