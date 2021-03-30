import numpy as np
import pandas as pd
import matplotlib.pyplot as plot
from sklearn.preprocessing import Imputer, LabelEncoder, OneHotEncoder, StandardScaler
from sklearn.model_selection import train_test_split
dataset = pd.read_csv('data.csv')
dataset1 = pd.read_csv('data1.csv')
X = dataset1.iloc[:, :-1].values
print(X)
Y = dataset1.iloc[:, 3].values
imputer = Imputer(missing_values='NaN', strategy = 'mean', axis = 0)
imputer = imputer.fit(X[:, 1:3])
print(imputer)
X[:, 1:3] = imputer.transform(X[:, 1:3])
labelencoder_x = LabelEncoder()
X[:, 0] = labelencoder_x.fit_transform(X[:, 0])
onehotencoder = OneHotEncoder(categorical_features=[0])
X = onehotencoder.fit_transform(X).toarray()
Y = labelencoder_x.fit_transform(Y)
x_train,x_test,y_train,y_test = train_test_split(X,Y,test_size=0.2,random_state=0)
sc_x = StandardScaler()
x_train = sc_x.fit_transform(x_train)
x_test = sc_x.transform(x_test)
