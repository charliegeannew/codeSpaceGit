##########################################################################
# File Name: bw.py
# Creat Time: 2021年07月13日 星期二 12时26分47秒
# Author :Charliegean
# Mail :wht905@gmail.com
##########################################################################
#!/usr/bin/env python3
# coding=utf-8
import math

def getBeginEndPoint(pointList):
    beginPoint=[]
    endPoint=[]
    if len(pointList) == 0:
        print("there is no point in pointList!")
        beginPoint=[0,0,0].copy()
        endPoint=[0,0,0].copy()
    else:
        beginPoint=pointList[0].copy()
        endPoint=pointList[0].copy()
        for i in range(1,len(pointList)):
            if(beginPoint[0]>pointList[i][0]):
                beginPoint[0]=pointList[i][0]
            if(beginPoint[1]>pointList[i][1]):
                beginPoint[1]=pointList[i][1]
            if(beginPoint[2]>pointList[i][2]):
                beginPoint[2]=pointList[i][2]
            if(endPoint[0]>pointList[i][0]):
                endPoint[0]=pointList[i][0]
            if(endPoint[1]>pointList[i][1]):
                endPoint[1]=pointList[i][1]
            if(endPoint[2]>pointList[i][2]):
                endPoint[2]=pointList[i][2]
    return beginPoint,endPoint

def getSuperTriangle(beginPoint,endPoint):
    triangle=[] 
    le=math.fabs(endPoint[0]-beginPoint[0])
    wi=math.fabs(endPoint[1]-beginPoint[1])
    triangle.append([beginPoint[0]-le/2,beginPoint[1],beginPoint[2]])
    triangle.append([beginPoint[0]+le*3/2,beginPoint[1],beginPoint[2]])
    triangle.append([beginPoint[0]+le/2,beginPoint[1]+2*wi,beginPoint[2]])
    return triangle

def ifPointInTriangleCircumcircle(point,triangle):
    res=False
    return res

def bw(pointList):
    trianglation=[]
    beginPoint,endPoint=getBeginEndPoint(pointList)
    trianglation.append(getSuperTriangle(beginPoint,endPoint))
    for point in pointList:
        badTriangle=[]
        for triangle in trianglation:
            if ifPointInTriangleCircumcircle(point,triangle):
                badTriangle.append(triangle)
        polygon=[]
    return trianglation

def main():
    print("hello world")

if __name__=="__main__":
    main()

