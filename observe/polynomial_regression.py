import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

dataset = pd.read_csv('Position_Salaries.csv')
X = dataset.iloc[:,1:-1].values
Y = dataset.iloc[:,2].values

from sklearn.linear_model import LinearRegression
regressor = LinearRegression()
regressor.fit(X,Y)
y_pred = regressor.predict(X)

from sklearn.preprocessing import PolynomialFeatures
poly_reg = PolynomialFeatures(degree = 4)
X_poly = poly_reg.fit_transform(X)
regressor_poly = LinearRegression()
regressor_poly.fit(X_poly,Y)

plt.scatter(X,Y,color='red')
plt.plot(X,y_pred,color='green')
plt.title('Position vs Salary')
plt.xlabel('Level')
plt.ylabel('Salary')
plt.show()

plt.scatter(X,Y,color='red')
plt.plot(X,regressor_poly.predict(X_poly),color='green')
plt.title('Position vs Salary')
plt.xlabel('Level')
plt.ylabel('Salary')
plt.show()

X_grid = np.arange(min(X),max(X)+0.1,0.1)
X_grid = X_grid.reshape((len(X_grid),1))
plt.scatter(X,Y,color='red')
plt.plot(X_grid,regressor_poly.predict(poly_reg.fit_transform(X_grid)),color='green')
plt.title('Position vs Salary')
plt.xlabel('Level')
plt.ylabel('Salary')
plt.show()

