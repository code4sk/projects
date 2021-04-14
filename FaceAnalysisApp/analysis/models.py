from django.db import models
from django.db.models.signals import pre_save
from django.template.defaultfilters import slugify
from Crypto import Cipher


def folder_name(instance, filename):
    print(filename)
    print(instance)
    return 'faces/{}/{}'.format(instance.person.person_id, filename)


class Person(models.Model):
    person_id = models.CharField(max_length=200)
    name = models.CharField(max_length=50)

    def __str__(self):
        return "{} - {}".format(self.name, self.person_id)


class Camera(models.Model):
    name = models.CharField(max_length=500, unique=True)
    url = models.CharField(max_length=500)

    def __str__(self):
        return self.name


class Pic(models.Model):
    image = models.ImageField(upload_to=folder_name, null=True)
    encoding = models.TextField(null=True)
    person = models.ForeignKey(Person, on_delete=models.CASCADE, null=True)

    def __str__(self):
        return self.person.name


def assign_person_id(sender, **kwargs):
    instance = kwargs['instance']
    ctr = 1
    instance.person_id = slugify(instance.name + ' ' + str(ctr))
    if Person.objects.filter(person_id=instance.person_id):
        ctr += 1
    instance.person_id = slugify(instance.name + ' ' + str(ctr))


pre_save.connect(assign_person_id, Person)
