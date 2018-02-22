'''
DMP - RNG
Random Number Generation
'''

from matplotlib import pyplot as plot
import random

def endTask():
    loop = 1
    while(loop == 1):
        if input() == "":
            loop = 0
            
xaxis = []
yaxis = []

finalRolls = []
rollVal = []
permaList = []
tempList = []
numOfFaces = 0
dieFaces = []
maxRoll = 0
maxList = []
minRoll = 0
minList = []
place = []

numOfDie = int(input("Number of die to roll: "))
for i in range(numOfDie):
    numOfFaces = int(input("How many faces: "))
    dieFaces.append(numOfFaces)
    tempList = []
    for i in range(1, numOfFaces + 1):
        dieVal = int(input("Value for face {0}: ".format(i))) 
        tempList.append(dieVal)
    permaList.append(tempList)

for i in range(numOfDie):
    maxList.append(max(permaList[i]))
    minList.append(min(permaList[i]))
maxRoll = sum(maxList)
minRoll = sum(minList)

print(minRoll)
print(maxRoll)

print(permaList)

r = int(input("Type a range to test: "))

for i in range(r):
    rollList = []
    for i in range(numOfDie):
        tempDieList = permaList[i]
        rollList.append(random.choice(tempDieList))
    finalRolls.append(sum(rollList))

for i in range(minRoll, maxRoll + 1):
    print(i, "appeared:", finalRolls.count(i) / r * 100, "% of the time", finalRolls.count(i), "times")
    yaxis.append(finalRolls.count(i) / r * 100)
    xaxis.append(i)

plot.title("Sum of {0} Dice".format(numOfDie))
plot.xlabel("Possible Rolls")
plot.ylabel("Probability (%)")
plot.xticks(range(minRoll, maxRoll + 1))
plot.bar(xaxis, yaxis, align = "center")
plot.show()

endTask()
