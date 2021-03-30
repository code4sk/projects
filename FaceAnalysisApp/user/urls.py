# from django.contrib import admin
from django.urls import path
from user.views import LoginView, LogoutView

app_name = 'user'

urlpatterns = [
    path('login/', LoginView.as_view(), name='login'),
    path('logout/', LogoutView.as_view(), name='logout'),
]