# Jason Custodio
# Machine Learning Homework 5


from Input import *


"""-----------------------"""
"""-------FUNCTIONS-------"""
"""-----------------------"""


# Train clusters, get train
def main():
    global clusterCenter, bestMse, bestClusterCenter, bestClusterList, \
        clusterList, bestClusterLabelList, clusterLabelList

    # Train
    for index in range(5):                                                      # Do 5 times
        clusterCenter = numpy.random.randint(17, size=(clusterK, attribute))    # 10 random cluster centers
        iteration = 0
        while not updateClusterCenter():                                        # Update cluster centers
            iteration += 1
        print("ITERATIONS " + str(index+1) + ": ", iteration)
        removeEmptyCluster()                                                    # Remove any empty clusters
        mse = meanSquareError()
        if bestMse > mse:                                                       # Find best out of 5 runs
            bestMse = mse
            bestClusterCenter = clusterCenter
            bestClusterList = clusterList
            bestClusterLabelList = clusterLabelList

    clusterCenter = bestClusterCenter
    clusterList = bestClusterList
    clusterLabelList = bestClusterLabelList

    print("\n\nBEST CLUSTER DATA")
    print("MSE:", bestMse)
    print("MSS:", meanSquareSeparation())
    print("ME: ", meanEntropy())

    print("\n\nTRAIN ACCURACY: ", classify())

    # Test
    clusterDistanceTest()
    removeEmptyClusterTest()
    print("TEST ACCURACY:  ", classifyTest())

    # Confusion Matrix
    print("\n\nConfusion Matrix: ")
    print(confusionMatrix)

    # Grayscale
    for index in range(len(clusterCenter)):
        grayScale = clusterCenter[index].reshape((8, 8))
        pyplot.imshow(grayScale, cmap='gray', )
        pyplot.savefig('figure' + str(index) + '.png')


# Find nearest cluster for each instance
def clusterDistance():
    global clusterList, clusterLabelList

    clusterList = []                                        # Holds list of points for every cluster
    clusterLabelList = []                                   # Holds labels for each instance of the clusters

    for index in range(clusterK):
        clusterList.append([])                              # Create empty K clusters
        clusterLabelList.append([])

    for index1 in range(len(trainFeature)):
        distanceList = []                                   # Holds all the distances of an instance to a cluster

        for index2 in range(len(clusterCenter)):
            distance = scipy.spatial.distance.euclidean(trainFeature[index1], clusterCenter[index2])
            distanceList.append(distance)

        minDistance = numpy.argmin(distanceList)            # Grab index of shortest distance to a cluster
        clusterList[minDistance].append(trainFeature[index1])
        clusterLabelList[minDistance].append(trainLabel[index1])


# Update the cluster center according to mean of cluster points
def updateClusterCenter():
    global clusterCenter

    clusterDistance()                                           # Sort instances to clusters according to distance

    newClusterCenter = []

    for index in range(len(clusterList)):                       # Get mean of cluster center
        if len(clusterList[index]) == 0:
            newClusterCenter.append(clusterCenter[index])
        else:
            clusterCenterMean = numpy.mean(clusterList[index], axis=0)
            newClusterCenter.append(clusterCenterMean)

    newClusterCenter = numpy.array(newClusterCenter)
    check = numpy.allclose(clusterCenter, newClusterCenter)     # Compare with old to see when to stop updating

    if check:
        return True
    else:
        clusterCenter = newClusterCenter                        # If different, update cluster
        return False


# Find mean square error of clusters (MINIMIZE THIS)
def meanSquareError():

    mseList = []                                    # Holds MSE for every cluster

    for index in range(len(clusterList)):
        distance = 0                                # Distance for every data point in cluster
        for instance in clusterList[index]:
            distance += scipy.spatial.distance.euclidean(instance, clusterCenter[index])

        mse = distance/len(clusterList[index])      # Calculate mean square error for one cluster
        mseList.append(mse)                         # Store in list until have MSE for all clusters

    averageMse = sum(mseList)/len(clusterList)      # Calculate average MSE for cluster set
    return averageMse


# Remove any clusters that doesn't have any data points
def removeEmptyCluster():
    global clusterCenter, clusterList, clusterLabelList

    newClusterCenter = []
    newClusterList = []
    newClusterLabelList = []

    for index in range(clusterK):
        if clusterList[index]:
            newClusterCenter.append(clusterCenter[index])
            newClusterList.append(clusterList[index])
            newClusterLabelList.append(clusterLabelList[index])

    clusterCenter = newClusterCenter
    clusterList = newClusterList
    clusterLabelList = newClusterLabelList


# Calculate mean square separation of cluster centers (MAXIMIZE this)
def meanSquareSeparation():
    numerator = 0
    length = len(clusterCenter)

    for index1 in range(length):
        for index2 in range(length-index1):
            numerator += scipy.spatial.distance.euclidean(clusterCenter[index1], clusterCenter[index1+index2])

    denominator = (length * (length-1))/2
    return numerator/denominator


# Calculate mean entropy of clusters
def meanEntropy():

    entropyList = []                # List of entropy of every cluster
    labelCount = []                 # Number of labels per cluster

    for cluster in clusterLabelList:

        labelCount.append(len(cluster))                                 # Get Number of labels

        count = numpy.sort(cluster)                                     # Sort ascending data
        count = [len(list(group)) for key, group in groupby(count)]     # Group data according to value
        count = numpy.array(count)                                      # Convert to numpy array
        count = count/len(count)                                        # Obtain probability

        countLog = numpy.log2(count)                                    # Obtain log base 2
        clusterEntropy = numpy.sum(count*countLog)                      # Sum of prob and log base 2 of prob

        entropyList.append(clusterEntropy)                              # Add entropy to list

    labelCount = numpy.array(labelCount)
    labelCount = labelCount/numpy.sum(labelCount)
    entropy = labelCount * entropyList

    entropySum = numpy.sum(entropy)
    return entropySum


# Find train accuracy
def classify():
    prediction = []
    correct = 0
    total = 0

    for cluster in clusterLabelList:
        label = mostCommon(cluster)
        prediction.append(label)

    for cluster, predict in zip(clusterLabelList, prediction):
        correct += cluster.count(predict)
        total += len(cluster)

    return correct/total


# Find most occurring element in list
def mostCommon(inputList):
    data = Counter(inputList)
    return data.most_common(1)[0][0]


"""--------------------"""
"""--------TEST--------"""
"""--------------------"""


# Find nearest cluster for each instance
def clusterDistanceTest():
    global testClusterList, testClusterLabelList

    for index in range(clusterK):
        testClusterList.append([])                              # Create empty K clusters
        testClusterLabelList.append([])

    for index1 in range(len(testFeature)):
        distanceList = []                                       # Holds all the distances of an instance to a cluster

        for index2 in range(len(clusterCenter)):
            distance = scipy.spatial.distance.euclidean(testFeature[index1], clusterCenter[index2])
            distanceList.append(distance)

        minDistance = numpy.argmin(distanceList)                # Grab index of shortest distance to a cluster
        testClusterList[minDistance].append(testFeature[index1])
        testClusterLabelList[minDistance].append(testLabel[index1])


# Classify using test values
def classifyTest():
    prediction = []
    correct = 0
    total = 0

    for cluster in testClusterLabelList:
        label = mostCommon(cluster)
        prediction.append(label)

    for cluster, predict in zip(testClusterLabelList, prediction):
        correct += cluster.count(predict)
        total += len(cluster)

    print(prediction)

    for i in range(len(testClusterLabelList)):
        for j in range(len(testClusterLabelList[i])):
            confusionMatrix[int(testClusterLabelList[i][j]), int(prediction[i])] += 1

    return correct/total


# Remove any clusters that doesn't have any data points
def removeEmptyClusterTest():
    global clusterCenter, testClusterList, testClusterLabelList

    newClusterCenter = []
    newClusterList = []
    newClusterLabelList = []

    for index in range(clusterK):
        if testClusterList[index]:
            newClusterCenter.append(clusterCenter[index])
            newClusterList.append(testClusterList[index])
            newClusterLabelList.append(testClusterLabelList[index])

    clusterCenter = newClusterCenter
    testClusterList = newClusterList
    testClusterLabelList = newClusterLabelList


"""-------------------------"""
"""--------Variables--------"""
"""-------------------------"""


clusterK = 30                                                           # Number of clusters
attribute = 64                                                          # Number of attributes
clusterCenter = numpy.random.randint(17, size=(clusterK, attribute))    # 10 random cluster centers
clusterList = []                                                        # Holds instances for all clusters
averageMseList = []                                                     # Holds MSE to find best MSE
clusterLabelList = []                                                   # Hold train cluster labels
clusterCenterList = []                                                  # Hold centers for train features

bestMse = 10000                                                         # Lowest Mse
bestClusterCenter = 0                                                   # For best of 5
bestClusterList = []                                                    # For best of 5
bestClusterLabelList = []                                               # For best of 5

testClusterList = []                                                    # Cluster list for test data
testClusterLabelList = []                                               # Cluster labels for test data

confusionMatrix = numpy.zeros((10, 10))
confusionMatrix = confusionMatrix.astype(int)


"""-----------------------"""
"""--------Process--------"""
"""-----------------------"""


if __name__ == '__main__':
    main()

