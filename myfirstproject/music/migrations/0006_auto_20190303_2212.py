# Generated by Django 2.1.5 on 2019-03-03 16:42

from django.db import migrations, models


class Migration(migrations.Migration):
    dependencies = [
        ('music', '0005_auto_20190303_2208'),
    ]

    operations = [
        migrations.AlterField(
            model_name='song',
            name='artist',
            field=models.ManyToManyField(related_name='song', to='music.Artist'),
        ),
    ]
