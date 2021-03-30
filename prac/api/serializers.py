from rest_framework import serializers
from .models import Product, Type
from datetime import datetime
from django.core.validators import MinLengthValidator
c = (('E', 'Electronics'), ('NE', 'Non Electronics'))


class TypeSerializer(serializers.Serializer):
    name = serializers.CharField(max_length=30)
    avg_price = serializers.IntegerField(min_value=0)

    def update(self, instance, validated_data):
        name = validated_data.get('name', instance.name)
        avg_price = validated_data.get('avg_price', instance.avg_price)
        instance.name = name
        instance.avg_price = avg_price
        instance.save()
        return instance

    def create(self, validated_data):
        # print(**validated_data.get('name'))
        name = validated_data.get('name')
        avg_price = validated_data.get('avg_price')
        a = Type.objects.create(name=name, avg_price=avg_price)
        return a


class FavSerializer(serializers.Serializer):
    date = serializers.DateField(default=datetime.now)
    product_id = serializers.CharField(validators=[MinLengthValidator(9)], max_length=18)
    product_name = serializers.CharField(max_length=20)
    m_name = serializers.CharField(max_length=20)
    type = TypeSerializer()

    def update(self, instance, validated_data):
        instance.product_id = validated_data.get('product_id', instance.product_id)
        instance.date = validated_data.get('date', instance.date)
        instance.m_name = validated_data.get('m_name', instance.m_name)
        instance.product_name = validated_data.get('product_name', instance.product_name)
        s = TypeSerializer(instance= instance.type, data=validated_data.get('type'))
        instance.save()
        return instance

    def create(self, validated_data):
        # b = Type.objects.filter(id=self.get_initial().get('type'))[0]
        # print(b)
        s = TypeSerializer(data=validated_data.get('type'))
        # print(s.get('name'))
        # type_name = validated_data.get('type').get('name')
        # type_price = validated_data.get('type').get('avg_price')
        # print(type_name, type_price)
        # # print(self.type)
        # t = Type.objects.filter(name=type_name, avg_price=type_price)[0]
        print(s.is_valid())
        print(s.save(), s.instance)
        date = validated_data.get('date')
        product_id = validated_data.get('product_id')
        product_name = validated_data.get('product_name')
        m_name = validated_data.get('m_name')
        a = Product.objects.create(date=date, product_id=product_id, product_name=product_name,
                                   m_name=m_name, type=s.instance)
        print(type(validated_data))
        print("hi")
        return a
        # print(self.get_initial().get(type))
        # pass

    def validate(self, data):
        # print(self.initial_data)
        return data

    def validate_type(self, value):
        # print(value)
        return value




