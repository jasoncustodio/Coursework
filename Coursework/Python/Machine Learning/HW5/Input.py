# Jason Custodio
# Machine Learning Homework 5


import numpy
import pandas
import scipy
from matplotlib import pyplot
import sklearn.preprocessing
import sklearn.model_selection
from sklearn import svm
from sklearn import metrics
import math
from itertools import groupby
from collections import Counter


"""--------------------------"""
"""--------PREPROCESS--------"""
"""--------------------------"""


print("\n\nPreprocess Start")


readData = pandas.read_csv("optdigits.train", dtype='float64', header=None).as_matrix()
trainFeature = readData[:, :-1]
trainLabel = numpy.ravel(readData[:, -1])


readData = pandas.read_csv("optdigits.test", dtype='float64', header=None).as_matrix()
testFeature = readData[:, :-1]
testLabel = numpy.ravel(readData[:, -1])


print("Preprocess End\n\n")

