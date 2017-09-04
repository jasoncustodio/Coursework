# Jason Custodio
# Machine Learning Homework 3


import numpy
import pandas
from matplotlib import pyplot
import sklearn.preprocessing
import sklearn.model_selection
from sklearn import svm
from sklearn import metrics


"""--------------------------"""
"""--------PREPROCESS--------"""
"""--------------------------"""


print("\n\nPreprocess Start")

url = 'https://archive.ics.uci.edu/ml/machine-learning-databases/spambase/spambase.data'
readData = pandas.read_csv(url, header=None, index_col=57)

trainFeature, testFeature, trainLabel, testLabel \
    = sklearn.model_selection.train_test_split(readData, readData.index.values, test_size=0.5)

# Create an instance of a StandardScaler that is fit to the training data
scaler = sklearn.preprocessing.StandardScaler().fit(trainFeature)

# Transform the training data based on that scaler and set the index values accordingly
trainFeature = pandas.DataFrame(scaler.transform(trainFeature), index=trainLabel)
trainFeature = trainFeature.as_matrix()

# Transform the testing data based on that same scaler and set the index values accordingly
testFeature = pandas.DataFrame(scaler.transform(testFeature), index=testLabel)
testFeature = testFeature.as_matrix()

print("Preprocess End")

