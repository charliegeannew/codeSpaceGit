##########################################################################
# File Name: dsWht.py
# Author: Charliegean
# mail: wht905@gmail.com
# Created Time: Mon Jul 19 23:34:02 2021
#########################################################################
#!/usr/bin/env python3
# coding=utf-8

class coordWht:
    def __init__(self,coord=[0,0,0]):
        self.x=coord[0]
        self.y=coord[1]
        self.z=coord[2]
    def printCoord(self):
        print(self.x,self.y,self.z)
    def copy(self):
        coord=coordWht([self.x,self.y,self.z])
        return coord

class pointWht:
    def __init__(self,coord=coordWht(),index=-1):
        self.coord=coord.copy()
        self.indexInList=index 
    def printPoint(self):
        print("this is ",self.indexInList,"th point")
        self.coord.printCoord()
    def copy(self):
        point=pointWht(self.coord,self.indexInList)
        return point
    
    def distanceFromPoint(self,point):
        dis=((self.coord.x-point.coord.x)**2+(self.coord.y-point.coord.y)**2+(self.coord.z-point.coord.z)**2)**0.5
        return dis 

class edgeWht:
    def __init__(self,bPoint=pointWht(),ePoint=pointWht(),index=-1):
        self.bPoint=bPoint.copy()
        self.ePoint=ePoint.copy()
        self.indexInList=index
    def printEdge(self):
        print("this is the ",self.indexInList,"th edge")
        self.bPoint.printPoint()
        self.ePoint.printPoint()
    def copy(self):
        edge=edgeWht(self.bPoint,self.ePoint,self.indexInList)
        return edge
    
    def distanceFromPoint(self,point):
        dis=0
        return dis

    def distanceFromEdge(self,edge):
        dis=0
        return dis

class triangleWht:
    def __init__(self,aPoint=pointWht(),bPoint=pointWht(),cPoint=pointWht(),aEdge=edgeWht(),bEdge=edgeWht(),cEdge=edgeWht(),index=-1):
        self.aPoint=aPoint.copy()
        self.bPoint=aPoint.copy()
        self.cPoint=cPoint.copy()
        self.aEdge=aEdge.copy()
        self.bEdge=bEdge.copy()
        self.cEdge=cEdge.copy()
        self.indexInList=index
    def printTriangle(self):
        print("this is the ",self.indexInList,"th triangle")
        self.aPoint.printPoint()
        self.aPoint.printPoint()
        self.aPoint.printPoint()
        self.aEdge.printEdge()
        self.aEdge.printEdge()
        self.aEdge.printEdge()
    def copy(self):
        triangle=triangleWht(self.aPoint,self.bPoint,self.cPoint,self.aEdge,self.bEdge,self.cEdge,self.indexInList)
        return triangle

temp=[1,2,3]
coord=coordWht(temp)
coord.printCoord()
coord2=coord.copy()
coord2.printCoord()
coord2.x=3
coord2.y=4
coord2.printCoord()
coord.printCoord()
point1=pointWht(coord,0)
point1.printPoint()
point2=pointWht(coord2,1)
point2.printPoint()