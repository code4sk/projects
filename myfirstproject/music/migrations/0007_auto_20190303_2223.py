# Generated by Django 2.1.5 on 2019-03-03 16:53

from django.db import migrations, models


class Migration(migrations.Migration):
    dependencies = [
        ('music', '0006_auto_20190303_2212'),
    ]

    operations = [
        migrations.AlterField(
            model_name='song',
            name='artist',
            field=models.ManyToManyField(related_name='songs', to='music.Artist'),
        ),
    ]
