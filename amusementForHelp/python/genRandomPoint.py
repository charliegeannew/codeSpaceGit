##########################################################################
# File Name: genRandomPoint.py
# Creat Time: 2021年07月12日 星期一 16时37分09秒
# Author :Charliegean
# Mail :wht905@gmail.com
##########################################################################
#!/usr/bin/env python3
# coding=utf-8
import random
import numpy as np
import matplotlib.pyplot as plt
import math

def writeFile(fileName,wList):
    with open(fileName,'w') as wfpt:
        lineIndex=0
        for line in wList:
            wfpt.write(',')
            wfpt.write(str(lineIndex))
            wfpt.write(',')
            lineIndex+=1
            for x in line:
                wfpt.write(str(x))
                wfpt.write(',')
            wfpt.write('\n')
        wfpt.close()

def genPoint(midPoint,r,t):
    if len(midPoint)<3 :
        print("the midPoint error!")
    point=[]
    R=random.uniform(0,r)
    theta=random.uniform(0,2*math.pi)
    phy=random.uniform(0,math.pi)
    x=0
    y=0
    z=0
    x=R*math.cos(theta)
    if t == 2:
        y=R*math.sin(theta)
        z=midPoint[2]
    elif t == 3:
        y=R*math.sin(theta)*math.cos(phy)
        z=R*math.sin(theta)*math.sin(phy)
    point.append(x)
    point.append(y)
    point.append(z)
    return point 

def genPointList(midPoint,r,t,num):
    pointList=[]
    for i in range(0,num):
        pointList.append(genPoint(midPoint,r,t))
    return pointList

def plot2DPoint(pointList):
    listX=[]
    listY=[]
    for x in pointList:
        listX.append(x[0])
        listY.append(x[1])
    plt.scatter(listX,listY)
    plt.show()

def main():
    print("hello world")
    midPoint=[0,0,0]
    r=5
    N=250
    t=2
    pointList=genPointList(midPoint,r,t,N)
    plot2DPoint(pointList)
    fileName="point.wht"
    writeFile(fileName,pointList)

if __name__=="__main__":
    main()

