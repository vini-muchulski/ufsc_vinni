# -*- coding: utf-8 -*-
"""ML UFSC

Automatically generated by Colab.

Original file is located at
    https://colab.research.google.com/drive/1X7WqUK79E3xLYgK02irsG8pgbw0pFRwM

# Regressão logistica

técnica de ml para classificação. existem tres tipos de regressão logistica

1 - regressao binaria - sim ou não

2 - regressão multinomial - é possivel ter varios valores de classificação

3 - regressão ordinal - é possivel ter varios valores de classificação, mas existe uma ordem(peso) para cada valor de saida.

a regressao logistica utiliza a funcao sigmoide como funcao base para gerar valores para a saida.

sigmoide = 1/ 1+ exp(-x)
"""

# Sigmoide - exemplo de funcionamentp
import numpy as np

def sigmoid(x):

  return 1/(1+np.exp(-x))

lista = [1,2,3,0,-2,-5,9,7]

for i in lista:
  print(sigmoid(i))

import matplotlib.pyplot as plt
y = []
x = np.arange(-10,10,0.1)

for i in x:
  y.append(sigmoid(i))

plt.plot(x,y)
plt.show()

import kagglehub

# Download latest version
path = kagglehub.dataset_download("uciml/pima-indians-diabetes-database")

print("Path to dataset files:", path)

print("/kaggle/input/pima-indians-diabetes-database/diabetes.csv")

import pandas as pd

df = pd.read_csv("/kaggle/input/pima-indians-diabetes-database/diabetes.csv")
df

df.shape

# separar atributos de entrada[features] e atributo de saida(target)

X = df.iloc[:,0:8].values
y = df.iloc[:,8].values

X

y

from sklearn.model_selection import train_test_split

X_train, X_test, y_train, y_test = train_test_split(X,y,test_size=0.25,random_state=0)

X_train.shape

X_test.shape

y_train.shape

y_test.shape

# configurar o algoritmo de ML
from sklearn.linear_model import LogisticRegression

lr = LogisticRegression()

lr .fit(X_train,y_train)

predicao = lr.predict(X_test)

predicao == y_test

from sklearn.metrics import confusion_matrix
import matplotlib.pyplot as plt
from sklearn.metrics import ConfusionMatrixDisplay

cm  =confusion_matrix(y_test,predicao)
cm

disp = ConfusionMatrixDisplay(confusion_matrix=cm)
disp.plot()
plt.show()

from yellowbrick.classifier import ConfusionMatrix
cm = ConfusionMatrix(lr)
#cm.fit(X_train,y_train)
cm.score(X_test,y_test)
cm.poof()

from sklearn.metrics import classification_report

print(classification_report(y_test, predicao))

lr.intercept_

lr.coef_

"""# KNN

algoritmo de aprendizado de maquina preguicoso, ou seja, há a necessidade de se ter os dados toda a vez que usar o algoritmo.

o knn é baseado em tecnicas de calculo de distancias. A distancia é calculada com gase nos vizinhos mais proximos.
"""

import kagglehub

# Download latest version
path = kagglehub.dataset_download("uciml/pima-indians-diabetes-database")

print("Path to dataset files:", path)
print("/kaggle/input/pima-indians-diabetes-database/diabetes.csv")

import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

dataset= pd.read_csv("/kaggle/input/pima-indians-diabetes-database/diabetes.csv")
dataset

X = dataset.iloc[:,0:8].values
y = dataset.iloc[:,8].values

X.shape, y.shape

from sklearn.model_selection import train_test_split

X_train, X_test, y_train, y_test = train_test_split(X,y)

X_train.shape, X_test.shape

from sklearn.neighbors import KNeighborsClassifier

knn = KNeighborsClassifier(n_neighbors=3)

knn.fit(X_train,y_train)

predicoes = knn.predict(X_test)

predicoes

predicoes

y_test

predicoes == y_test

from sklearn.metrics import confusion_matrix

cm = confusion_matrix(y_test, predicoes)
print(cm)

from sklearn.metrics import accuracy_score

accuracy_score(y_test, predicoes)

"""## knn vs regressao logistica"""

from sklearn.linear_model import LogisticRegression

lr = LogisticRegression()
lr.fit(X_train,y_train)

predicoes_lr = lr.predict(X_test)

from yellowbrick.classifier import ConfusionMatrix

cmlr = ConfusionMatrix(lr)
cmlr.fit(X_train,y_train)
cmlr.score(X_test,y_test)
cmlr.poof();

print(accuracy_score(y_test, predicoes_lr))

"""## dataset cancer de mama - knn vs reg_log"""

import kagglehub

# Download latest version
path = kagglehub.dataset_download("yasserh/breast-cancer-dataset")

print("Path to dataset files:", path)
#print("/kaggle/input/pima-indians-diabetes-database/diabetes.csv")

import os
os.listdir('/root/.cache/kagglehub/datasets/yasserh/breast-cancer-dataset/versions/1')

!ls

import pandas as pd

data_set = pd.read_csv(f'/root/.cache/kagglehub/datasets/yasserh/breast-cancer-dataset/versions/1/breast-cancer.csv')
data_set.head()

data_set.shape

data_set.info()

X = data_set.iloc[:, 2:].values
y = data_set.iloc[:, 1].values

X.shape, y.shape

y

from sklearn.model_selection import train_test_split

X_treino, X_teste, y_treino, y_teste = train_test_split(X, y)

X_treino.shape, X_teste.shape

from sklearn.neighbors import KNeighborsClassifier

knn = KNeighborsClassifier(n_neighbors=5)


knn.fit(X_treino, y_treino)

from yellowbrick.classifier import confusion_matrix

cm = confusion_matrix(knn, X_teste, y_teste)

from sklearn.metrics import accuracy_score

predicoes = knn.predict(X_teste)
ac = accuracy_score(y_teste, predicoes)

print(ac)

from sklearn.metrics import classification_report

print(classification_report(y_teste, predicoes))

"""## regressao logistica

"""

from sklearn.linear_model import LogisticRegression

lr = LogisticRegression()

lr.fit(X_treino, y_treino)

predicoes_lr = lr.predict(X_teste)

cm_lr = confusion_matrix(lr, X_teste, y_teste)

print(accuracy_score(y_teste, predicoes_lr))

print(classification_report(y_teste, predicoes_lr))