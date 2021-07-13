##########################################################################
# File Name: bw.py
# Creat Time: 2021年07月13日 星期二 12时26分47秒
# Author :Charliegean
# Mail :wht905@gmail.com
##########################################################################
#!/usr/bin/env python3
# coding=utf-8
import math
import genRandomPoint as grw 
import ds 

def getNewPointList(pointList):
    res=[]
    index=0
    for x in pointList:
        point=ds.pointWht(x,index)
        res.append(point)
        index+=1
    return res

def getBeginEndPointCoord(pointList):
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
            if(endPoint[0]<pointList[i][0]):
                endPoint[0]=pointList[i][0]
            if(endPoint[1]<pointList[i][1]):
                endPoint[1]=pointList[i][1]
            if(endPoint[2]<pointList[i][2]):
                endPoint[2]=pointList[i][2]
    return beginPoint,endPoint

def getSuperTrianglePointCoord(beginPoint,endPoint):
    triangle=[]
    le=math.fabs(endPoint[0]-beginPoint[0])
    wi=math.fabs(endPoint[1]-beginPoint[1])
    triangle.append([beginPoint[0]-le/2,beginPoint[1],beginPoint[2]])
    triangle.append([beginPoint[0]+le*3/2,beginPoint[1],beginPoint[2]])
    triangle.append([beginPoint[0]+le/2,beginPoint[1]+2*wi,beginPoint[2]])
    return triangle

def ifPointInTriangleCircumcircle(point,triangle,pointIndexList):
    res=False
    return res

def bw(pointList):
    beginPoint,endPoint=getBeginEndPointCoord(pointList)
    pointListWht=getNewPointList(pointList)

    superTriangleCoord=getSuperTrianglePointCoord(beginPoint,endPoint)

    pointNum=len(pointListWht)
    pointIndexList=[0,0,0]
    temp=ds.pointWht(superTriangleCoord[0],pointNum)
    pointListWht.append(temp)
    pointIndexList[0]=pointNum
    pointNum+=1
    temp=ds.pointWht(superTriangleCoord[1],pointNum)
    pointListWht.append(temp)
    pointIndexList[1]=pointNum
    pointNum+=1
    temp=ds.pointWht(superTriangleCoord[2],pointNum)
    pointListWht.append(temp)
    pointIndexList[2]=pointNum
    pointNum+=1
    
    # pointList+=superTriangleCoord
    # grw.plot2DPoint(pointList)

    edgeIndex=[0,1,2]
    edgeListWht=[]
    edge=ds.edgeWht([pointIndexList[1],pointIndexList[2]],0)
    edgeListWht.append(edge)
    edge=ds.edgeWht([pointIndexList[2],pointIndexList[0]],1)
    edgeListWht.append(edge)
    edge=ds.edgeWht([pointIndexList[0],pointIndexList[1]],2)
    edgeListWht.append(edge)

    # for x in pointListWht:
    #     x.printPoint()

    trianglation=[]
    triangleFlag=[]
    edgeUserFlagList=[0 for x in edgeListWht]
    badEdgeUserFlagList=[0 for x in edgeListWht]
    
    superTriangle=ds.triangleWht(pointIndexList,edgeIndex,0)
    trianglation.append(superTriangle)
    triangleFlag.append(1)

    for x in edgeIndex:
        edgeUserFlagList[x]+=1

    for point in pointListWht:
        badTriangle=[]
        badTriangleFlag=[]
        for triangle in trianglation:
            if ifPointInTriangleCircumcircle(point,triangle,pointListWht):
                badTriangle.append(triangle)
                badTriangleFlag.append(1)
                badEdgeUserFlagList[triangle.aEdgeIndex]+=1
                badEdgeUserFlagList[triangle.bEdgeIndex]+=1
                badEdgeUserFlagList[triangle.cEdgeIndex]+=1
        polygon=[]
        for triangle in badTriangle:
            if badEdgeUserFlagList[triangle.aEdgeIndex]<=1:
                polygon.append(triangle.aEdgeIndex)
            if badEdgeUserFlagList[triangle.bEdgeIndex]<=1:
                polygon.append(triangle.bEdgeIndex)
            if badEdgeUserFlagList[triangle.cEdgeIndex]<=1:
                polygon.append(triangle.cEdgeIndex)

        for triangle in badTriangle:
            triangleFlag[triangle.tIndex]=0
        for edge in polygon:
            tempEdgeIndex=[0,0,0]
            tempPointIndex=[0,0,0]
            newTriangle=ds.triangleWht(tempPointIndex,tempEdgeIndex,len(trianglation))
            trianglation.append(newTriangle)
            triangleFlag.append(0)
    for triangle in trianglation:
        pass
    return trianglation

def main():
    print("hello world")
    midPoint=[0,0,0]
    r=5
    N=250
    t=2
    pointList=grw.genPointList(midPoint,r,t,N)
    # grw.plot2DPoint(pointList)
    bw(pointList)
    pointListWht=getNewPointList(pointList)

    # for x in pointListWht:
    #     x.printPoint()

if __name__=="__main__":
    main()

