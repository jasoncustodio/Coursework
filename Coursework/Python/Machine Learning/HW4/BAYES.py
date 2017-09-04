# Jason Custodio
# Machine Learning Homework 4


from Input import *


"""-----------------------"""
"""-------FUNCTIONS-------"""
"""-----------------------"""


# Find prior probability, split training data, find mean and standard deviation, then classify
def main():
    split()
    meanStdDev()
    classify()


# Compute the prior probability for each class: 1(spam) and 0(not-spam)
def prior():
    count = 0
    for label in trainLabel:
        if label == 1:
            count += 1                              # Number of spam in train set

    spamProbability = count/len(trainLabel)         # Spam percentage in train set
    notSpamProbability = 1-spamProbability          # Not spam percentage in train set

    print("\n\nSpam Percent:     ", spamProbability)
    print("Not Spam Percent: ", notSpamProbability)
    return spamProbability, notSpamProbability


# Split training data into either spam and not spam
def split():
    global spam, notSpam

    for featureSet, label in zip(trainFeature, trainLabel):
        if label == 1:
            spam.append(featureSet)
        else:
            notSpam.append(featureSet)

    spam = numpy.array(spam)
    notSpam = numpy.array(notSpam)


# Compute the mean and standard deviation for each feature
def meanStdDev():
    global spamMean, spamStdDev, notSpamMean, notSpamStdDev

    spamMean = spam.mean(axis=0)
    spamStdDev = spam.std(axis=0)

    notSpamMean = notSpam.mean(axis=0)
    notSpamStdDev = notSpam.std(axis=0)


# Compute gaussian function to classify, midStd is 0.0001
def gaussian(x, m, s):
    if s == 0:
        s = minStd
    return 1/(math.sqrt(2*math.pi)*s) * math.exp(-((x-m)**2/(2*s**2)))


# Classify the test set and create statistic data along with confusion matrix
def classify():
    for i in range(len(testFeature)):

        positive = []                                   # Hold feature set for spam
        negative = []                                   # Hold feature set for not spam

        for j in range(column):

            spamPdf = gaussian(testFeature[i, j], spamMean[j], spamStdDev[j])
            notSpamPdf = gaussian(testFeature[i, j], notSpamMean[j], notSpamStdDev[j])

            positive.append(spamPdf)
            negative.append(notSpamPdf)

        spamLog = numpy.log(positive)                   # Log all values for spam
        notSpamLog = numpy.log(negative)                # Log all values for not spam

        positiveSum = spamP + numpy.sum(spamLog)        # Spam classification probability
        negativeSum = notSpamP + numpy.sum(notSpamLog)  # Not spam classification probability

        if positiveSum > negativeSum:                   # Check which probability is higher to classify
            prediction.append(1)
        else:
            prediction.append(0)

        confusionMatrix[testLabel[i], prediction[i]] += 1

    print("\n\nAccuracy: ", metrics.accuracy_score(testLabel, prediction))
    print("Precision:", metrics.precision_score(testLabel, prediction))
    print("Recall:   ", metrics.recall_score(testLabel, prediction))
    print("\n\n", confusionMatrix)


"""-------------------------"""
"""--------Variables--------"""
"""-------------------------"""


minStd = 0.0001                     # Minimal standard deviation to avoid divide by zero error
column = 57                         # Number of feature columns in data set

(spamP, notSpamP) = prior()         # Prior probabilities
spamP = math.log(spamP)             # Log of spam probability log(~0.40)
notSpamP = math.log(notSpamP)       # Log of not spam probability log(~0.60)

spam = []                           # Hold all spam sets
spamMean = []                       # Hold mean of spam features
spamStdDev = []                     # Hold standard deviation of spam features

notSpam = []                        # Hold all not spam sets
notSpamMean = []                    # Hold mean of not spam features
notSpamStdDev = []                  # Hold standard deviation of not spam features

prediction = []                     # Gaussian Naive Baye classifier results
confusionMatrix = numpy.zeros((2, 2))
confusionMatrix = confusionMatrix.astype(int)


"""-----------------------"""
"""--------Process--------"""
"""-----------------------"""


if __name__ == '__main__':
    main()

