# Jason Custodio
# Machine Learning Homework 3


from Input import *


"""-----------------------"""
"""-------FUNCTIONS-------"""
"""-----------------------"""


# Experiment 1
def experiment1():
    print("\n\nAccuracy: ", accuracy)
    print("Precision: ", precision)
    print("Recall: ", recall)
    plotROC()


# Experiment 2
def experiment2():
    processFeatureSelection(reverseWeight, featureSelectionAccuracy, 2)


# Experiment 3
def experiment3():
    processFeatureSelection(randomWeight, randomFeatureSelectionAccuracy, 3)


# Select strongest features or randomly
def processFeatureSelection(inputWeight, inputAccuracy, experiment):
    for m in range(2, 58):
        trainM = trainFeature[:, inputWeight[:m]]           # Select next highest feature by slicing columns
        testM = testFeature[:, inputWeight[:m]]             # Fix test features to reflect new training set

        classifier.fit(trainM, trainLabel)                  # Train with only features selected
        featureAccuracy = classifier.score(testM, testLabel)

        inputAccuracy.append(featureAccuracy)

    plotFeatureSelection(inputAccuracy, experiment)


# Plot ROC curve using pyplot
def plotROC():
    pyplot.figure(1)

    fpr, tpr, threshold = metrics.roc_curve(testLabel, probability[:, -1])
    pyplot.plot([0, 1], [0, 1], color='red', linewidth=1, linestyle='--', label='Random')
    pyplot.plot(fpr, tpr, linewidth=2, label='ROC Curve')   # Plot fpr as x-axis, tpr as y-axis

    pyplot.title("Experiment 1")                            # Create plot title
    pyplot.ylabel("True Positive Rate")                     # Y-axis label
    pyplot.xlabel("False Positive Rate")                    # X-axis label
    pyplot.legend(loc=4)                                    # Create legend in the lower right corner
    pyplot.grid(True)                                       # Create a grid lines

    pyplot.savefig('Experiment1.png')


# Plot feature selection using pyplot
def plotFeatureSelection(inputAccuracy, experiment):
    pyplot.figure(experiment)

    featureM = numpy.arange(2, 58)
    pyplot.plot(featureM, inputAccuracy, linewidth=2, label='Test Accuracy')

    pyplot.xlim([0.0, 58])                                  # Limit x-axis
    pyplot.ylim([0.6, 1.0])                                 # Limit y-axis

    pyplot.title("Experiment " + str(experiment))           # Create plot title
    pyplot.ylabel("Test Accuracy")                          # Y-axis label
    pyplot.xlabel("M")                                      # X-axis label
    pyplot.legend(loc=4)                                    # Create legend in the lower right corner
    pyplot.grid(True)                                       # Create a grid lines

    pyplot.savefig('Experiment' + str(experiment) + '.png')


"""-------------------------"""
"""--------Variables--------"""
"""-------------------------"""


# Experiment 1
classifier = svm.SVC(kernel='linear', probability=True)         # Create SVM with linear kernel
classifier = classifier.fit(trainFeature, trainLabel)           # Train SVM with test features and label
weight = classifier.coef_                                       # Generated weight vector by SVM
prediction = classifier.predict(testFeature)                    # Create prediction array for precision/recall
probability = classifier.predict_proba(testFeature)             # Probabilities for classifying
accuracy = classifier.score(testFeature, testLabel)             # Find accuracy on test features
precision = metrics.precision_score(testLabel, prediction)      # Find precision
recall = metrics.recall_score(testLabel, prediction)            # Find recall


# Experiment 2
absolute = numpy.ravel(abs(weight))                             # Obtain absolute magnitudes for vector
indexSort = numpy.argsort(absolute)                             # Create array holding sorted index values
reverseWeight = numpy.flipud(indexSort)                         # Reverse the array to hold largest values first
featureSelectionAccuracy = []                                   # Hold accuracies for feature selection


# Experiment 3
randomWeight = numpy.ravel(weight)                              # Change shape of weight
randomWeight = numpy.argsort(randomWeight)                      # Change to sorted index values
numpy.random.shuffle(randomWeight)                              # Shuffle weights
randomFeatureSelectionAccuracy = []                             # Holds accuracies for random feature selection


"""-----------------------"""
"""--------Process--------"""
"""-----------------------"""


# Run all experiments
experiment1()
experiment2()
experiment3()
