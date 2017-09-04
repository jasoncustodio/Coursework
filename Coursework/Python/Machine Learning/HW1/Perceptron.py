# Jason Custodio
# Machine Learning Homework 1


import numpy as np
import pandas as pd
from matplotlib import pyplot as plt


"""-----------------------"""
"""-------FUNCTIONS-------"""
"""-----------------------"""


# Preprocess input data, target lists, and bias
def preprocess(inputData, row, targetList):
    for i in range(0, row):                     # Create target list to compare
        targetList.append(int(inputData[i][0]))

    for i in range(0, row):                     # Create bias of 1
        inputData[i][0] = 1

    for i in range(0, row):                     # Divide all elements by 255
        for j in range(0, column):
            inputData[i][j] = inputData[i][j] * (1.0 / 255.0)


# Find how accurate the perceptron recognizes digits
def findAccuracy(rate):
    p = Perceptron(rate)

    print("\n\nLearning Rate: ", rate)
    for i in range(0, maxEpoch):
        print("\nEPOCH: ", i)

        p.calculate(trainData, trainRow, trainTarget)
        trainPercent = (p.correct / trainRow) * 100
        trainAccuracy.append(trainPercent)
        p.correct = 0
        print("Train Percent: ", trainPercent, "%")

        p.calculate(testData, testRow, testTarget)
        testPercent = (p.correct / testRow) * 100
        testAccuracy.append(testPercent)
        p.correct = 0
        print("Test  Percent: ", testPercent, "%")

        p.train(trainRow, trainTarget)

    p.confusion(testData, testRow, testTarget)

    print("\n\nCONFUSION MATRIX:\n", confusionMatrix)

    plotAccuracy(rate)


# Plot accuracy using pyplot
def plotAccuracy(rate):

    epoch = []
    for i in range(0, maxEpoch):
        epoch.append(i)

    plt.plot(epoch, trainAccuracy, linewidth=2, label='Train')  # Plot epoch as x-axis, trainAccuracy as y-axis
    plt.plot(epoch, testAccuracy, linewidth=1, label='Test')    # Plot epoch as x-axis, testAccuracy as y-axis

    plt.title("Perceptron Accuracy LR: " + str(rate))           # Create plot label
    plt.ylabel("Percent Accuracy")                              # Y-axis label
    plt.xlabel("Epoch")                                         # X-axis label
    plt.legend()                                                # Create legend for the the lines
    plt.grid(True, 'k')                                         # Create a black grid

    plt.show()                                                  # Show plot created


"""--------------------------"""
"""--------PREPROCESS--------"""
"""--------------------------"""

maxEpoch = 51                               # Number of epochs to do including initial
testRow = 10000                             # Number of testing input sets
trainRow = 60000                            # Number of training input sets
column = 785                                # Number of inputs per set
trainTarget = []                            # List of training data targets
testTarget = []                             # List of testing data targets
trainAccuracy = []                          # Hold list of accuracies for train data
testAccuracy = []                           # Hold list of accuracies for test data
target = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]     # Select which digit to recognize (0-9)
confusionMatrix = np.zeros((10, 10))        # Confusion matrix 10 by 10 array
confusionMatrix = confusionMatrix.astype(int)


print("\n\nPreprocess Start")
readData = pd.read_csv("mnist_train.csv", header=None).as_matrix()
trainData = np.asfarray(readData)

readData = pd.read_csv("mnist_test.csv", header=None).as_matrix()
testData = np.asfarray(readData)

preprocess(trainData, trainRow, trainTarget)
preprocess(testData, testRow, testTarget)
print("Preprocess End")


"""---------------------"""
"""-------CLASSES-------"""
"""---------------------"""


class Perceptron:

    weight = np.random.uniform(-0.05, 0.05, size=(10, column))  # 785 weights ranging from -0.5 to 0.5
    output = np.zeros(10)                                       # Output of dot products
    correct = 0                                                 # Number of correct answers

    def __init__(self, rate):
        self.rate = rate                                        # Learning Rate

        for index in range(0, 10):                              # Shuffle weights
            np.random.shuffle(self.weight[index])

    def confusion(self, inputData, row, targetList):            # Epoch 0
        for index in range(0, row):                             # Go through all rows of input data
            actual = self.calculateDigit(inputData[index])      # Find actual digit
            predicted = targetList[index]                       # Store predicted digit
            confusionMatrix[actual, predicted] += 1

    def calculate(self, inputData, row, targetList):            # Epoch 0
        for index in range(0, row):                             # Go through all rows of input data
            digit = self.calculateDigit(inputData[index])       # Return the highest dot product's index
            if digit == targetList[index]:                      # If highest dot product is same as target
                self.correct += 1                               # Increase correct

    def calculateDigit(self, x):                                # Calculate correct digit index
        for index in range(0, 10):
            self.output[index] = np.dot(x, self.weight[index])  # Store dot product

        maxDot = np.amax(self.output)                           # Find max dot product
        for index in range(0, 10):
            if self.output[index] == maxDot:                    # Find index (0-9) that corresponds
                return index

    def train(self, row, targetList):                           # Train using train data and update weights
        for indexOne in range(0, 10):
            for indexTwo in range(0, row):
                y = self.checkY(self.weight[indexOne], trainData[indexTwo])
                t = self.checkT(indexOne, indexTwo, targetList)
                if y != t:
                    self.updateWeight(t, y, self.weight[indexOne], trainData[indexTwo])

    def updateWeight(self, t, y, w, x):                         # Update weight algorithm
        for index in range(0, column):
            newWeight = self.rate * (t - y) * x[index]
            w[index] += newWeight

    @staticmethod
    def checkT(indexOne, indexTwo, targetList):                 # Assign each perceptron to recognize 1 digit
        return 1 if target[indexOne] == targetList[indexTwo] else 0

    @staticmethod
    def checkY(w, x):                                           # Dot product of weight and input vectors
        output = np.dot(w, x)
        return 1 if output > 0 else 0
