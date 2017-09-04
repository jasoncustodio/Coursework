# Jason Custodio
# Machine Learning Homework 6


import numpy
import random
from matplotlib import pyplot


"""-----------------------"""
"""-------FUNCTIONS-------"""
"""-----------------------"""


def main():

    # Map
    qMatrix = dict()            # qMatrix to update
    resetMatrix(qMatrix)

    # Q-Learning
    epsilon = 1.0               # Epsilon for greedy action

    # Rewards
    rewardList = []             # Hold rewards for episodes
    rewardSumList = []
    rewardSum = 0

    testRewardList = []

    # Train
    for episode in range(episodes):
        totalReward = 0                                                 # initialize total rewards
        currentPosition = (random.randint(0, 9), random.randint(0, 9))  # Random start
        grid = numpy.random.randint(2, size=(10, 10))                   # 0 = empty, 1 = can

        if (episode + 1) % 50 == 0 and epsilon > 0.1:                   # Update epsilon for greedy action selection
            epsilon -= .01

        # Stepping through grid
        for index in range(steps):

            state = sensor(currentPosition, grid)                               # Observe current state

            qValueList = qMatrix[state]

            action = chooseAction(epsilon, state, qValueList)                   # Choose which action to do

            newPosition, reward = performAction(currentPosition, action, grid)  # Perform Action
            totalReward += reward                                               # Total reward for episode

            newState = sensor(newPosition, grid)                                # Find state of new position

            updateMatrix(qMatrix, state, newState, action, reward)              # Update qMatrix

            currentPosition = newPosition                                       # Step through grid with new position

        rewardSum += totalReward
        if (episode+1) % 100 == 0:
            rewardList.append(totalReward)
            rewardSumList.append(rewardSum/100)
            rewardSum = 0

    plotReward(rewardList, rewardSumList)

    # Test
    for episode in range(episodes):

        epsilon = 0
        totalReward = 0                                                         # initialize total rewards
        currentPosition = (random.randint(0, 9), random.randint(0, 9))          # Random start
        grid = numpy.random.randint(2, size=(10, 10))                           # 0 = empty, 1 = can

        for index in range(steps):
            state = sensor(currentPosition, grid)                               # Observe current state

            qValueList = qMatrix[state]

            action = chooseAction(epsilon, state, qValueList)                   # Choose which action to do

            newPosition, reward = performAction(currentPosition, action, grid)  # Perform Action
            totalReward += reward                                               # Total reward for episode

            currentPosition = newPosition                                       # Step through grid with new position

        testRewardList.append(totalReward)                                      # Hold total rewards

    testMean = numpy.mean(testRewardList)                                       # Test reward mean
    testStd = numpy.std(testRewardList)                                         # Test reward standard deviation
    print("TEST MEAN: ", testMean)
    print("TEST STD:  ", testStd)


# Sets all values to 0
def resetMatrix(qMatrix):

    for i1 in range(3):
        for i2 in range(3):
            for i3 in range(3):
                for i4 in range(3):
                    for i5 in range(3):
                        key = (i1, i2, i3, i4, i5)
                        qMatrix[key] = [0, 0, 0, 0, 0]


# Check current and adjacent areas
def sensor(currentPosition, grid):

    state = []                          # (Here, North, East, South, West)

    x = currentPosition[0]              # Row
    y = currentPosition[1]              # Column

    north = (x - 1, y)                  # Cell to the north (state[1])
    east = (x, y + 1)                   # Cell to the east  (state[2])
    south = (x + 1, y)                  # Cell to the south (state[3])
    west = (x, y - 1)                   # Cell to the west  (state[4])

    state.append(grid[x, y])            # Current cell (state[0])

    if x == 0:                          # Check north wall
        state.append(2)
    else:
        state.append(grid[north])

    if y == 9:                          # Check east wall
        state.append(2)
    else:
        state.append(grid[east])

    if x == 9:                          # Check south wall
        state.append(2)
    else:
        state.append(grid[south])

    if y == 0:                          # Check west wall
        state.append(2)
    else:
        state.append(grid[west])

    return tuple(state)


# Choose action according to greedy action
def chooseAction(epsilon, state, qValueList):

    greedy = 1 - epsilon
    length = len(state)

    checkGreedy = numpy.random.choice(2, 1, p=[epsilon, greedy])    # Choose 1 random number based on probabilities 'p'

    if checkGreedy[0] == 1:                                         # If the greedy chance wins
        action = numpy.argmax(qValueList)                           # Choose action with highest value in qValueList
    else:
        randomChoice = numpy.random.choice(length, 1)               # Else, choose randomly.
        action = randomChoice[0]

    return action                                                   # 0: Pick Up, 1: N, 2: E, 3: S, 4: W


# Perform action according to new state with potential rewards
def performAction(currentPosition, action, grid):

    x = currentPosition[0]  # Row
    y = currentPosition[1]  # Column

    reward = 0

    if action == 0:                     # Pick Up
        if grid[x, y] == 1:
            grid[x, y] = 0
            reward = canReward
        else:
            reward = emptyReward

    elif action == 1:                   # North
        if x == 0:
            reward = wallReward
        else:
            x -= 1

    elif action == 2:                   # East
        if y == 9:
            reward = wallReward
        else:
            y += 1

    elif action == 3:                   # South
        if x == 9:
            reward = wallReward
        else:
            x += 1

    else:                               # West
        if y == 0:
            reward = wallReward
        else:
            y -= 1

    newPosition = (x, y)

    return newPosition, reward


# Updates qMatrix
def updateMatrix(qMatrix, state, newState, action, reward):

    qValueList = qMatrix[state]
    currentValue = qValueList[action]               # Q(s(t), a)
    maxQValue = max(qMatrix[newState])              # max Q(s(t+1), a)

    update = maxQValue * learningRate               # y * maxQValue
    update += reward                                # r + (y * maxQValue)
    update -= currentValue                          # r + (y * maxQValue) - Q(s(t), a)
    update *= discount                              # n * (r + (y * maxQValue) - Q(s(t), a))
    update += currentValue                          # Q(s(t), a) + (n * (r + (y * maxQValue) - Q(s(t), a)))

    qMatrix[state][action] = update                 # Updated Q(s(t), a)


# Plot rewards
def plotReward(rewardList, rewardSumList):

    xAxis = numpy.arange(100, episodes+1, 100)
    pyplot.figure()

    pyplot.plot(xAxis, rewardList, color='red', linewidth=1, linestyle='--', label='Reward')
    pyplot.plot(xAxis, rewardSumList, color='blue', linewidth=2, label='Average Reward')

    pyplot.xlim([0, episodes])              # Limit x-axis
    pyplot.ylim([0, 500])                   # Limit y-axis

    pyplot.title("Part 5 Discount: 0.1")    # Create plot title
    pyplot.ylabel("Total Rewards")          # Y-axis label
    pyplot.xlabel("Episodes")               # X-axis label
    pyplot.legend(loc=2)                    # Create legend in the upper left corner
    pyplot.grid(True)                       # Create a grid lines

    pyplot.savefig('Part5.png')
    # pyplot.show()


"""-----------------------"""
"""--------Constants------"""
"""-----------------------"""


episodes = 5000                                                 # Number of episodes to take
steps = 200                                                     # Number of steps per episode

learningRate = 0.1                                              # Learning rate     (I switched the naming scheme)
discount = 0.20                                                 # Discount value    (I switched the naming scheme)

canReward = 10                                                  # +10 reward for picking up a can
wallReward = -5                                                 # Hitting a wall penalty
emptyReward = -1                                                # Trying to pick up in an empty cell


"""-----------------------"""
"""--------Process--------"""
"""-----------------------"""


if __name__ == '__main__':
    main()
