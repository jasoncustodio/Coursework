# Jason Custodio
# Machine Learning Homework 4


import numpy
import pandas
from matplotlib import pyplot
import sklearn.preprocessing
import sklearn.model_selection
from sklearn import svm
from sklearn import metrics
import math


"""--------------------------"""
"""--------PREPROCESS--------"""
"""--------------------------"""


print("\n\nPreprocess Start")

url = 'https://archive.ics.uci.edu/ml/machine-learning-databases/spambase/spambase.data'
readData = pandas.read_csv(url, header=None, index_col=57)

trainFeature, testFeature, trainLabel, testLabel \
    = sklearn.model_selection.train_test_split(readData, readData.index.values, test_size=0.5)

trainFeature = trainFeature.as_matrix()
testFeature = testFeature.as_matrix()

print("Preprocess End")

