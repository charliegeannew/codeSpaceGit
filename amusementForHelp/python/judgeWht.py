##########################################################################
# File Name: judgeWht.py
# Creat Time: 2021年07月20日 星期二 17时07分20秒
# Author :Charliegean
# Mail :wht905@gmail.com
##########################################################################
#!/usr/bin/env python3
# coding=utf-8
import math
import pythonHelp.dsWht as ds
import pythonHelp.constantWht as ct
# import dsWht as ds
# import constantWht as ct
import numpy as np 

def ifPointInTriangleCircumcircle_bak(point,triangle):
    flag=False
    r=5
    coord1=[triangle.aPoint.coord.x,triangle.aPoint.coord.y,0]
    coord2=[triangle.bPoint.coord.x,triangle.bPoint.coord.y,0]
    coord3=[triangle.cPoint.coord.x,triangle.cPoint.coord.y,0]
    res=[0,0,0]
    tempDivid=2*((coord1[0]*(coord2[1]-coord3[0])-coord1[0]*(coord1[1]-coord3[1])+coord2[0]*(coord1[1]-coord2[1])))
    temp=[0,0,0]
    temp[0]=coord1[0]**2+coord1[1]**2
    temp[1]=coord2[0]**2+coord2[1]**2
    temp[2]=coord3[0]**2+coord3[1]**2
    tempX=(temp[0])*(coord2[1]-coord3[1])-(temp[1])*(coord1[1]-coord3[1])+(temp[2])*(coord1[1]-coord2[1])
    tempY=(coord1[0])*(temp[1]-temp[2])-(coord2[0])*(temp[0]-temp[2])+(coord3[0])*(temp[0]-temp[1])
    dis=0
    if math.fabs(tempDivid)<ct.threshold:
        flag=True 
    else:
        res[0]=tempX/tempDivid
        res[1]=tempY/tempDivid
        newPoint=ds.pointWht(ds.coordWht(res),0)
        dis=newPoint.distanceFromPoint(point)
        if dis > r:
            flag=True 
    print("flag === ",flag)
    print("divbid is ",tempDivid)
    print("tempX is ",tempX)
    print("tempY is ",tempY)
    print("res is  ",res)
    print("coord1: ",coord1)
    print("coord2: ",coord2)
    print("coord3: ",coord3)
    print("dis is ",dis)
    print("((((((((((((((((((((((((()))))))))))))))))))))))))")
    return flag 

def ifPointInTriangleCircumcircle(point,triangle):
    flag=False#false in true not in
    # point.printPoint()
    # triangle.aPoint.printPoint()
    # triangle.bPoint.printPoint()
    # triangle.cPoint.printPoint()

    angle1=calPointAngle2D(point,triangle.bPoint,triangle.cPoint)
    angle2=calPointAngle2D(triangle.aPoint,triangle.bPoint,triangle.cPoint)
    p0=np.array([point.coord.x,point.coord.y])
    p1=np.array([triangle.aPoint.coord.x,triangle.aPoint.coord.y])
    p2=np.array([triangle.bPoint.coord.x,triangle.bPoint.coord.y])
    p3=np.array([triangle.cPoint.coord.x,triangle.cPoint.coord.y])
    # print("p0 === ",p0)
    # print("p1 === ",p1)
    # print("p2 === ",p2)
    # print("p3 === ",p3)
    A=p3-p0
    B=p2-p0 
    # print("A === ",A)
    # print("B === ",B)
    C=np.cross(A,B)
    A=p3-p1
    B=p2-p1
    # print("A === ",A)
    # print("B === ",B)
    D=np.cross(A,B)
    temp=C*D
    # print("C==== ",C)
    # print("D==== ",D)
    # print("temp==== ",temp)
    
    # print("angle1 is ",angle1)
    # print("angle2 is ",angle2)
    if math.fabs(angle1)<ct.threshold:
        flag=True
    elif math.fabs(angle1-math.pi)<ct.threshold:
        flag=False
    else:
        if temp>=ct.threshold:
            if angle2>=angle1:
                flag=True 
            else:
                flag=False
        else:
            if angle1+angle2>=math.pi:
                flag=False
            else:
                flag=True
    return flag

def calPointAngle2D(anglePoint,bPoint,ePoint):
    vec1=[]
    vec2=[]
    sumV=0
    vec1.append(bPoint.coord.x-anglePoint.coord.x)
    vec1.append(bPoint.coord.y-anglePoint.coord.y)
    vec2.append(ePoint.coord.x-anglePoint.coord.x)
    vec2.append(ePoint.coord.y-anglePoint.coord.y)
    temp1=0
    temp2=0
    # print(vec1)
    # print(vec2)
    for i in range(0,2):
        sumV+=vec1[i]*vec2[i]
        temp1+=vec1[i]**2
        temp2+=vec2[i]**2
    temp1=temp1**0.5
    temp2=temp2**0.5
    if temp1<ct.threshold:
        angle=math.pi
    else:
        if temp2<ct.threshold:
            angle=math.pi
        else:
            angle=math.acos(sumV/temp1/temp2)
    # angle=angle*180/math.pi
    return angle

def main():
    # print("hello world")
    coord=ds.coordWht([-2.25,1.32,0])
    coord1=ds.coordWht([-6.75,-3.86,0])
    coord2=ds.coordWht([6.94,-3.86,0])
    coord3=ds.coordWht([0.1,12.5,0])
    
    point=ds.pointWht(coord,0)
    point1=ds.pointWht(coord1,1)
    point2=ds.pointWht(coord2,2)
    point3=ds.pointWht(coord3,3)
    edge1=ds.edgeWht(point1,point2,0)
    edge2=ds.edgeWht(point2,point3,1)
    edge3=ds.edgeWht(point3,point1,2)
    # print(calPointAngle(point1,point2,point3))

    triangle=ds.triangleWht(point1,point2,point3,edge1,edge2,edge3,0);
    # print("====")
    # triangle.printTriangle()
    # print("----------------------====")
    res=ifPointInTriangleCircumcircle(point,triangle)
    print("res is ",res)


if __name__=="__main__":
    main()

