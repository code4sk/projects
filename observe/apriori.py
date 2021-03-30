import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

dataset = pd.read_csv('Market_Basket_Optimisation.csv', header = None)
transactions = []
"""for i in range(0,7501):
    lists = []
    for j in dataset.iloc[i, :]:
        lists.append(str(j))
    transactions.append(lists)"""

for i in range(0, 7501):
    transactions.append([str(dataset.values[i, j]) for j in range(0, 20)])

from apyori import apriori
rules = apriori(transactions, min_support = 0.03, min_confidence = 0.2, min_lift = 3, min_length = 2)
results = list(rules)
