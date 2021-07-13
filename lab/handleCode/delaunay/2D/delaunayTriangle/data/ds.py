##########################################################################
# File Name: ds.py
# Creat Time: 2021年07月13日 星期二 16时26分28秒
# Author :Charliegean
# Mail :wht905@gmail.com
##########################################################################
#!/usr/bin/env python3
# coding=utf-8

class pointWht:
    def __init__(self,coord=[0,0,0],index=-1):
        self.coord=coord.copy()
        self.pIndex=index 

    def pointCopyFrom(self,sPoint):
        self.coord=sPoint.coord.copy()
        self.pInde=sPoint.pIndex

    def printPoint(self):
        print("this is the ",self.pIndex,"th point:")
        print("the coord is ",self.coord)

    coord=[0,0,0]
    pIndex=-1

class edgeWht:
    def __init__(self,pointIndex,fIndex=-1):
        self.fIndex=fIndex 
        self.bPointIndex=pointIndex[0]
        self.ePointIndex=pointIndex[1]

    def edgeCopyFrom(self,sEdge):
        self.bPointIndex=sEdge.bPointIndex
        self.ePointIndex=sEdge.ePointIndex
        self.fIndex=sEdge.fIndex

    def printEdge(self):
        print("this is the ",self.fIndex,"th edge:")
        print("the bPoint index is ",self.bPointIndex)
        print("the ePoint index is ",self.ePointIndex)

    bPointIndex=0
    ePointIndex=0
    fIndex=-1

class triangleWht:
    def __init__(self,pointIndex=[0,0,0],edgeIndex=[0,0,0],tIndex=-1):
        self.aPointIndex=pointIndex[0]
        self.bPointIndex=pointIndex[1]
        self.cPointIndex=pointIndex[2]
        self.aEdgeIndex=edgeIndex[0]
        self.bEdgeIndex=edgeIndex[1]
        self.cEdgeIndex=edgeIndex[2]
        self.tIndex=tIndex

    def triangleCopyFrom(self,sTriangle):
        self.aPointIndex=sTriangle.aPointIndex
        self.bPointIndex=sTriangle.bPointIndex
        self.cPointIndex=sTriangle.cPointIndex
        self.aEdgeIndex=sTriangle.aEdgeIndex
        self.bEdgeIndex=sTriangle.bEdgeIndex
        self.cEdgeIndex=sTriangle.cEdgeIndex
        self.tIndex=sTriangle.tIndex

    def printTriangle(self):
        print("this is the ",self.tIndex,"th triangle:")
        print("the PointIndex (a,b,c) is (",self.aPointIndex,self.bPointIndex,self.cPointIndex,")")
        print("the edgeIndex (a,b,c) is (",self.aEdgeIndex,self.bEdgeIndex,self.cEdgeIndex,")")

    aPointIndex=0
    bPointIndex=0
    cPointIndex=0
    
    aEdgeIndex=0
    bEdgeIndex=0
    cEdgeIndex=0

    tIndex=-1

def main():
    print("hello world")
    aPoint=pointWht([-1,0,0],0)
    bPoint=pointWht([1,0,0],1)
    cPoint=pointWht([0,2,0],2)
    aPoint.printPoint()
    bPoint.printPoint()
    cPoint.printPoint()
    
    pointIndex=[2,1]
    aEdge=edgeWht(pointIndex,0)
    pointIndex=[0,2]
    bEdge=edgeWht(pointIndex,1)
    pointIndex=[1,0]
    cEdge=edgeWht(pointIndex,2)

    aEdge.printEdge()
    bEdge.printEdge()
    cEdge.printEdge()

    pointIndex=[0,1,2]
    edgeIndex=[0,1,2]
    triangle=triangleWht(pointIndex,edgeIndex,0)

    triangle.printTriangle()

if __name__=="__main__":
    main()

