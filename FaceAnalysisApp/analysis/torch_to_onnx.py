# Some standard imports
import io
import numpy as np

from torch import nn
import torch.utils.model_zoo as model_zoo
import torch.onnx

# Super Resolution model definition in PyTorch
import torch.nn as nn
import torch.nn.init as init


import numpy as np
import time
import argparse

import cv2

import torch
from torch.utils.data import Dataset, DataLoader
from torchvision import datasets, models, transforms
from retinanet import model
from retinanet.dataloader import CocoDataset, CSVDataset, collater, Resizer, AspectRatioBasedSampler, Augmenter, \
    UnNormalizer, Normalizer
import imageio
import skimage


model_url = 'csv_retinanet_latest.pt'
# retinanet = torch.load(parser.model_path, map_location=torch.device('cpu'))
# retinanet = torch.load(parser.model_path)#, map_location=torch.device('cpu'))
torch_model = model.resnet50(num_classes=3, pretrained=True)
# retinanet.load_state_dict(torch.load(parser.model_path))




# Initialize model with the pretrained weights
map_location = torch.device('cpu')
if torch.cuda.is_available():
    map_location = None
torch_model.load_state_dict(model.load_url(model_url, map_location=map_location))

# set the model to inference mode
torch_model.eval()



# Input to the model
x = torch.randn(batch_size, 1, 224, 224, requires_grad=True)
torch_out = torch_model(x)

# Export the model
torch.onnx.export(torch_model,               # model being run
                  x,                         # model input (or a tuple for multiple inputs)
                  "retinanet.onnx",   # where to save the model (can be a file or file-like object)
                  export_params=True,        # store the trained parameter weights inside the model file
                  opset_version=10,          # the ONNX version to export the model to
                  do_constant_folding=True,  # whether to execute constant folding for optimization
                  input_names = ['input'],   # the model's input names
                  output_names = ['output'], # the model's output names
                  dynamic_axes={'input' : {0 : 'batch_size'},    # variable lenght axes
                                'output' : {0 : 'batch_size'}})


