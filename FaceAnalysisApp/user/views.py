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
        email = request.POST.get('email')
        username = request.POST.get('username')
        password = request.POST.get('password')
        print('ok')
        user = User.objects.filter(email=email, username=username)
        if user:
            print('ok')
            user = user[0]
            if user.check_password(password):
                login(request, user)
                return redirect('analysis:upload')
            return redirect('user:login')
        else:
            return redirect('user:login')


class LogoutView(View):
    def get(self, request):
        logout(request)
        return redirect('user:login')
