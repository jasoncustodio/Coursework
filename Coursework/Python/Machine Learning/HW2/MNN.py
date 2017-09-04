# Jason Custodio
# Machine Learning Homework 2


from Input import *


"""-----------------------"""
"""-------FUNCTIONS-------"""
"""-----------------------"""


# Find Accuracy
def findAccuracy():
    global correct

    calculateOutputTarget()

    print("\n\nMomentum:      ", momentum)
    print("Hidden Units:  ", hiddenNode - hiddenBias)
    print("Learning Rate: ", rate)

    for i in range(maxEpoch):
        print("\nEPOCH: ", i)

        calculate(trainData, trainSet, trainTarget)
        trainPercent = (correct / trainSet) * 100
        trainAccuracy.append(trainPercent)
        correct = 0
        print("Train Percent: ", trainPercent, "%")

        calculate(testData, testSet, testTarget)
        testPercent = (correct / testSet) * 100
        testAccuracy.append(testPercent)
        correct = 0
        print("Test Percent: ", testPercent, "%")

        train()

    confusion(testData, testSet, testTarget)

    print("\n\nCONFUSION MATRIX:\n", confusionMatrix)

    plotAccuracy()


# Train NN using training data
def train():
    for index in range(trainSet):
        calculateOuter(trainData[index])
        backPropagation(outputTarget[index], trainData[index])


# Back propagate to update weights, factor in 1 Hidden Bias
def backPropagation(targetList, inputData):
    global inputWeight, hiddenWeight, newInputWeight, newHiddenWeight, outputError, hiddenError

    outputError = outputLayer * (1 - outputLayer) * (targetList - outputLayer)

    hiddenError = hiddenLayer * (1 - hiddenLayer) * (numpy.transpose(hiddenWeight).dot(outputError))

    newHiddenWeight = rate * numpy.transpose([outputError]) * hiddenLayer + (momentum * newHiddenWeight)
    hiddenWeight += newHiddenWeight

    hiddenError = hiddenError[1:]
    newInputWeight = rate * numpy.transpose([hiddenError]) * inputData + (momentum * newInputWeight)
    inputWeight += newInputWeight


# Sigmoid activation
def sigmoid(x):
    return 1 / (1 + numpy.exp(-x))


# Create list of output targets (0.9 = correct, 0.1 = incorrect)
def calculateOutputTarget():
    for index in range(trainSet):
        i = trainTarget[index]
        outputTarget[index, i] = 0.9


# Find accuracy
def calculate(inputData, inputSet, targetList):
    global correct
    for index in range(inputSet):
        calculateOuter(inputData[index])
        classification = returnMax()
        if classification == targetList[index]:
            correct += 1


# Input layer to Output layer
def calculateOuter(inputData):
    global outputLayer

    for index in range(hiddenNode - hiddenBias):
        hiddenDot = numpy.dot(inputWeight[index], inputData)
        hiddenLayer[index + hiddenBias] = sigmoid(hiddenDot)

    outputDot = numpy.dot(hiddenWeight, hiddenLayer)
    outputLayer = sigmoid(outputDot)


# Return classification of Neural Network
def returnMax():
    classification = numpy.amax(outputLayer)
    for index in range(outputNode):
        if outputLayer[index] == classification:
            return index


# Calculate Confusion Matrix
def confusion(inputData, inputSet, targetList):
    for index in range(inputSet):
        calculateOuter(inputData[index])
        actual = returnMax()
        predicted = targetList[index]
        confusionMatrix[actual, predicted] += 1


"""-------------------------"""
"""--------Variables--------"""
"""-------------------------"""


# Correct answers
correct = 0

# Learning rate
rate = 0.1
momentum = 0

# Number of nodes per layer
outputNode = 10
hiddenNode = 101  # Including 1 bias
inputNode = 785

# Bias
hiddenBias = 1

# Layers of Neural Network
outputLayer = numpy.zeros(outputNode)
hiddenLayer = numpy.zeros(hiddenNode)
hiddenLayer[0] = 1.0  # Bias

# Input -> Hidden, Hidden -> Output
inputWeight = numpy.random.uniform(-0.05, 0.05, size=(hiddenNode - hiddenBias, inputNode))
hiddenWeight = numpy.random.uniform(-0.05, 0.05, size=(outputNode, hiddenNode))
newInputWeight = numpy.zeros((hiddenNode - hiddenBias, inputNode))
newHiddenWeight = numpy.zeros((outputNode, hiddenNode))

# Error
outputError = numpy.zeros(outputNode)
hiddenError = numpy.zeros(hiddenNode - hiddenBias)

# Output Target List
outputTarget = numpy.random.uniform(0.1, 0.1, size=(trainSet, outputNode))


"""-----------------------"""
"""--------Process--------"""
"""-----------------------"""


findAccuracy()
