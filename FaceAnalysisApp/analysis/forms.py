from django import forms
from analysis.models import Camera


class CameraForm(forms.ModelForm):
    class Meta:
        model = Camera
        fields = ('name', 'url',)
