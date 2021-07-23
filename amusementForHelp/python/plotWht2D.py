##########################################################################
# File Name: plotWht2D.py
# Creat Time: 2021年07月20日 星期二 13时03分56秒
# Author :Charliegean
# Mail :wht905@gmail.com
##########################################################################
#!/usr/bin/env python3
# coding=utf-8
import tkinter as tk
import numpy as np
import math

def initCanvas(windowsName):
    window=tk.Tk()
    window.title(windowsName)
    window.geometry('1000x900')
    canvas = tk.Canvas(window,width=900,height=810,bg='white')
    canvas.place(x=50,y=45)
    return window,canvas

def getBegEndCoord(coordList):
    if len(coordList)<=0:
        print("the list has no coord!!!")
    else:
        beginCoord=coordList[0].copy()
        endCoord=coordList[0].copy()
        for i in range(1,len(coordList)):
            if beginCoord[0]>coordList[i][0]:
                beginCoord[0]=coordList[i][0]
            if beginCoord[1]>coordList[i][1]:
                beginCoord[1]=coordList[i][1]
            if endCoord[0]<coordList[i][0]:
                endCoord[0]=coordList[i][0]
            if endCoord[1]<coordList[i][1]:
                endCoord[1]=coordList[i][1]
        # print(beginCoord,endCoord)
        return beginCoord,endCoord

def changeCoordToCanvasCoord(coord,beginCoord,endCoord):
    dxmax=(endCoord[0]-beginCoord[0])*1.2
    dymax=(endCoord[1]-beginCoord[1])*1.2
    xscale=dxmax/900
    yscale=dymax/810
    sx=int((coord[0]-beginCoord[0]+dxmax*0.083)/xscale)
    sy=int((endCoord[1]-coord[1]+dymax*0.083)/yscale)
    return sx,sy

def drawCoord(coordList,canvas):
    beginCoord,endCoord=getBegEndCoord(coordList)
    for coord in coordList:
        sxsy=changeCoordToCanvasCoord(coord,beginCoord,endCoord)
        # print(sxsy)
        oval = canvas.create_oval(sxsy[0]-5,sxsy[1]-5,sxsy[0]+5,sxsy[1]+5)
        # canvas.create_text(sxsy[0]-13,sxsy[1],text=str(sxsy))

def drawLine(lineList,canvas):
    for line in lineList:
        newLine=[]
        temp=canvas.create_line(line[0][0],line[0][1],line[1][0],line[1][1], fill = 'blue')

def main():
    print("hello world")
    windowsName="test"
    window,canvas=initCanvas(windowsName)
    coordList=[
        [0,0],
        [1,0],
        [2,2],
        [3,5],
        [4,3],
        [2.5,8],
        [1.5,6],
    ]
    newCoordList=[]
    beginCoord,endCoord=getBegEndCoord(coordList)
    for coord in coordList:
        newCoordList.append(changeCoordToCanvasCoord(coord,beginCoord,endCoord))
    lineList=[]
    for i in range(0,len(coordList)):
        tempLine=[]
        tempLine.append(newCoordList[i])
        tempLine.append(newCoordList[(i+1)%len(coordList)])
        lineList.append(tempLine)
    for line in lineList:
        print(line)
    # print(coordList)
    drawCoord(coordList,canvas)
    drawLine(lineList,canvas)
    window.mainloop()

if __name__=="__main__":
    main()

