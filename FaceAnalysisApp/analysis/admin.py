from django.contrib import admin
from analysis.models import Pic, Person, Camera
from user.models import User

admin.site.register(Pic)
admin.site.register(Person)
admin.site.register(User)
admin.site.register(Camera)

# Register your models here.
