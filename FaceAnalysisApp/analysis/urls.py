from django.contrib import admin
from django.urls import path
from analysis.views import Upload, DisplayImage, Train, DeletePerson, face_recognition, FaceAnalysis,\
    get_faces, CreateDataset, DeleteImage, CreateCamera
from analysis.capture_face import capture_face, save_face

app_name = 'analysis'

urlpatterns = [
    path('upload/', Upload.as_view(), name='upload'),
    path('display-image/<person_id>/', DisplayImage.as_view(), name='display-image'),
    path('image/delete/<id>/', DeleteImage.as_view(), name='delete-image'),
    path('delete-person/<person_id>/', DeletePerson.as_view(), name='delete-person'),
    path('face-analysis/', FaceAnalysis.as_view(), name='face-analysis'),
    path('face-recognition/<camera_id>/', face_recognition, name='face-recognition'),
    path('train/', Train.as_view(), name='train'),
    path('get-faces/', get_faces, name='get-faces'),
    path('create-dataset/<person_id>/', CreateDataset.as_view(), name='create-dataset'),
    path('capture-face/<camera_id>/', capture_face, name='capture-face'),
    path('save-face/<person_id>/', save_face, name='save-face'),
    path('create-camera/', CreateCamera.as_view(), name='create-camera')
]