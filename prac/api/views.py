from django.shortcuts import render
from rest_framework import viewsets
from .models import Product
from .serializers import FavSerializer, TypeSerializer
from rest_framework import generics
from rest_framework.views import APIView
from rest_framework.generics import ListAPIView
from rest_framework.response import Response
from rest_framework.authentication import BasicAuthentication
from rest_framework.renderers import JSONRenderer
from django.shortcuts import Http404
import json
from rest_framework.parsers import JSONParser


class ProductApiView(APIView):
    authentication_classes = ()
    serializer_class = FavSerializer
    parser_classes = [JSONParser]

    # def get_object(self, pk):
    #     try:
    #         return Product.objects.get(pk=pk)
    #     except Product.DoesNotExist:
    #         raise Http404

    def get(self, request, **kwargs):
        products = Product.objects.all()
        # print(self.request.query_params.get('val'))
        serializers = FavSerializer(instance=products, many=True)
        # print(serializers.instance)
        # print(serializers.is_valid())
        # data = serializers.validated_data
        # print(data)
        # print(serializers.errors)
        # json = JSONRenderer().render(serializers.data)
        # print(json)
        print('hi')
        # print(serializers.is_valid())
        # print(serializers.errors)
        return Response(serializers.data, status=200, headers={'api': 'rest'})

    def post(self, request, format=None):
        j = request.data
        print(j['type'])
        serializer = FavSerializer(data=request.data)
        if serializer.is_valid():
            serializer.save()
            return Response({"data": "valid"}, status=200)
        else:
            return Response({"data": "not valid", "reason": serializer.errors}, status=300)

    def put(self,request,pk):
        # instance = self.get_object(pk)
        instance = Product.objects.get(pk=pk)
        serializer = FavSerializer(instance, data=request.data)
        if serializer.is_valid():
            serializer.save()
            return Response({"data": "valid"}, status=200)
        else:
            return Response({"data":"not valid", "reason": serializer.errors}, status=300)

    def delete(self, request, pk):
        instance = Product.objects.get(pk=pk)
        print('lets see')
        samp = instance
        instance.delete()
        samp = FavSerializer(data=samp)
        samp.is_valid()
        return Response(samp.data, status=200)
