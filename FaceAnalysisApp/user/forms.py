from django import forms
from user.models import User


class LoginForm(forms.ModelForm):
    class Meta:
        model = User
        fields = ('email', 'client_id', 'password',)
