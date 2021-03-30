from django.shortcuts import render
from django.views.generic import View
from user.forms import LoginForm
from django.contrib.auth import authenticate, login, logout
from django.shortcuts import redirect
from django.contrib.auth.hashers import make_password
from user.models import User


class LoginView(View):
    def get(self, request):
        # form = LoginForm()
        return render(request, 'user/login.html')
        # return render(request, 'user/login.html', {'form': form})

    def post(self, request):
        form = LoginForm(request.POST)
        if form.is_valid():
            user = User.objects.filter(client_id=form.cleaned_data.get('client_id'))
            if user:
                user = user[0]
                if user.check_password(form.cleaned_data.get('password')):
                    login(request, user)
                    return redirect('analysis:upload')
                return redirect('user:login')
            else:
                return redirect('user:login')
        else:
            return redirect('analysis:upload')

class LogoutView(View):
    def get(self, request):
        logout(request)
        return redirect('user:login')
