# Generated by Django 2.2.12 on 2020-07-18 10:24

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('analysis', '0003_auto_20200714_2218'),
    ]

    operations = [
        migrations.AddField(
            model_name='pic',
            name='encoding',
            field=models.TextField(null=True),
        ),
    ]