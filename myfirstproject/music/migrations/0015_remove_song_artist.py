# Generated by Django 2.1.5 on 2019-03-04 08:23

from django.db import migrations


class Migration(migrations.Migration):

    dependencies = [
        ('music', '0014_song'),
    ]

    operations = [
        migrations.RemoveField(
            model_name='song',
            name='artist',
        ),
    ]
