# Jason Custodio
# Machine Learning Homework 2


import numpy
import pandas
from matplotlib import pyplot


"""-----------------------"""
"""-------FUNCTIONS-------"""
"""-----------------------"""


# Preprocess for Experiment 3
def preprocessTrain(inputData, row, targetList):

    for i in range(row):                        # Create target list to compare
        targetList.append(int(inputData[i][0]))

    for i in range(row):                        # Divide all elements by 255
        for j in range(0, column):
            inputData[i][j] = inputData[i][j] * (1.0 / 255.0)

    for inputSet in inputData:
        numpy.random.shuffle(inputSet)          # Shuffle each set

    quarter = int(row/4)

    inputData = inputData[:quarter]             # Split in two

    for inputSet in inputData:                  # Create bias of 1
        inputSet[0] = 1


# Preprocess input data, target lists, and bias
def preprocess(inputData, row, targetList):

    for i in range(row):                        # Create target list to compare
        targetList.append(int(inputData[i][0]))

    for i in range(row):                        # Divide all elements by 255
        for j in range(0, column):
            inputData[i][j] = inputData[i][j] * (1.0 / 255.0)

    for inputSet in inputData:
        numpy.random.shuffle(inputSet)          # Shuffle each set

    for inputSet in inputData:                  # Create bias of 1
        inputSet[0] = 1


# Plot accuracy using pyplot
def plotAccuracy():

    epoch = []
    for i in range(0, maxEpoch):
        epoch.append(i)

    pyplot.plot(epoch, trainAccuracy, linewidth=2, label='Train')   # Plot epoch as x-axis, trainAccuracy as y-axis
    pyplot.plot(epoch, testAccuracy, linewidth=1, label='Test')     # Plot epoch as x-axis, testAccuracy as y-axis

    pyplot.title("Experiment 2")                                    # Create plot label
    pyplot.ylabel("Neural Network Accuracy")                        # Y-axis label
    pyplot.xlabel("Epoch")                                          # X-axis label
    pyplot.legend()                                                 # Create legend for the the lines
    pyplot.grid(True, 'k')                                          # Create a black grid

    pyplot.show()                                                   # Show plot created


"""--------------------------"""
"""--------PREPROCESS--------"""
"""--------------------------"""


maxEpoch = 51                                   # Number of epochs to do including initial
testSet = 10000                                 # Number of testing input sets
trainSet = 60000                                # Number of training input sets
column = 785                                    # Number of inputs per set
trainTarget = []                                # List of training data targets
testTarget = []                                 # List of testing data targets
trainAccuracy = []                              # Hold list of accuracies for train data
testAccuracy = []                               # Hold list of accuracies for test data
confusionMatrix = numpy.zeros((10, 10))         # Confusion matrix 10 by 10 array
confusionMatrix = confusionMatrix.astype(int)


print("\n\nPreprocess Start")
readData = pandas.read_csv("mnist_train.csv", header=None).as_matrix()
trainData = numpy.asfarray(readData)

readData = pandas.read_csv("mnist_test.csv", header=None).as_matrix()
testData = numpy.asfarray(readData)

preprocess(trainData, trainSet, trainTarget)
preprocess(testData, testSet, testTarget)
print("Preprocess End")
