import pandas as pd
df = pd.read_csv('data1.csv')
x = df.iloc[0:7,:].values
print(x)