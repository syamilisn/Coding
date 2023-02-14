import pandas as pd
import numpy as np
from sklearn import preprocessing

# data = np.array(pd.read_csv('dataset.csv'))
data = pd.read_csv('dataset.csv')
print(data.columns)
print(data.dtypes)

le = preprocessing.LabelEncoder()
data=le.fit_transform(data)
integerMapping = get_integer_mapping(le)
print(data)
data.to_csv('normaldata.csv', index= False)