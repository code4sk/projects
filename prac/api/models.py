from django.db import models
from datetime import datetime
from django.core.validators import MinLengthValidator
from django.contrib.auth.models import AbstractUser

choices = (('E', 'Electronics'), ('NE', 'Non Electronics'))


class Type(models.Model):
    name = models.CharField(max_length=20)
    avg_price = models.PositiveIntegerField()

    def __str__(self):
        return self.name


class Product(models.Model):
    date = models.DateField(default=datetime.now)
    product_id = models.CharField(validators=[MinLengthValidator(9)], max_length=18)
    product_name = models.CharField(max_length=20)
    m_name = models.CharField(max_length=20)
    type = models.ForeignKey(Type, default=None, on_delete=models.CASCADE)

    def __str__(self):
        return self.product_name


# class CustomUser(AbstractUser):
#     power = models.CharField(max_length=20)
