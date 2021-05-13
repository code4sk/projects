import pandas as pd
import numpy as np
import math
import sys

dataset = pd.read_csv('Social_Network_Ads.csv')
X = dataset.iloc[:, 2:4].values
Y = dataset.iloc[:, 4].values

from sklearn.model_selection import train_test_split

x_train, x_test, y_train, y_test = train_test_split(X, Y, test_size = 0.25, random_state = 0)

from sklearn.preprocessing import StandardScaler
sc_x = StandardScaler()
x_train = sc_x.fit_transform(x_train)
x_test = sc_x.transform(x_test)

alpha = 0.280

m = 300

MAX = sys.float_info.max
MIN = sys.float_info.min

def sigmoid(x):
    try:
        return 1 / (1 + math.exp(-x))
    except:
        if x > 0:
            return 1
        else:
            return 0
    return 1 / (1 + math.exp(-x))
  

def loss(y, y_cap):
    if y_cap == 1:
        return MAX 
    if y_cap == 0:
        return 0
    if y == 1:
        L = -1*(y*math.log(y_cap))
    else:
        L =  -1*((1-y)*math.log(1-y_cap))
    return L

# print(y_train[0])

def getResult(x_test, y_test, size):
    correct = 0
    incorrect = 0

    for i in range(0, size):
        x1 = x_test[i][0]
        x2 = x_test[i][1]
        y = y_test[i]
        z = w1*x1 + w2*x2 + b
        z = sigmoid(z)
        
        if(abs(y - z) > 0.5):
            incorrect += 1
        else:
            correct += 1
            
    print("correct = ", correct)
    print("incorrect = ", incorrect)

w1 = 0
w2 = 0 
b = 0

print(sys.float_info.max, sys.float_info.min)

for ab in range(1, 2001):
    J = 0
    dw1 = 0
    dw2 = 0
    db = 0
    if ab%100 == 0:
        alpha -= 0.01
    for i in range(0, m):
        x1 = x_train[i][0]
        x2 = x_train[i][1]
        y = float(y_train[i])
        z = w1*x1 + w2*x2 + b
        y_cap = sigmoid(z)
        # print(y, y_cap)
        J += loss(y, y_cap)
        dw1 += (y-y_cap)*x1
        dw2 += (y-y_cap)*x2
        b += (y- y_cap)
    
    J /= m
    print(J)
    dw1 /= m
    dw2 /= m
    db /= m
    # print(dw1, dw2)
    w1 = w1 + alpha*dw1
    w2 = w2 + alpha*dw2
    b = b + alpha*db

# w1 = -43455102.04812532
# w2 = -43455102.04812532
# b = -187988.14710646064
    
print(w1, w2, b)

getResult(x_train, y_train, m)

print("NOW test")

getResult(x_test, y_test, 100)

