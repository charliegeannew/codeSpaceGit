##########################################################################
# File Name: readWriteFileWht.py
# Author: Charliegean
# mail:wht905@gmail.com
# Created Time: Fri Jul  9 23:48:46 2021
#########################################################################
#!/usr/bin/env python3
# coding=utf-8

def readFileDirect(fileName):
    res=''
    with open(fileName,'r') as rfpt:
        res=rfpt.read()
    rfpt.close()
    return res

def readFileLine(fileName):
    res=[]
    with open(fileName,'r+') as rfpt:
        for line in rfpt.readlines():
            # print(line)
            res.append(line)
    rfpt.close()
    return res

def writeFileDirect(fileName,tData):
    pass

def writeFileLine(fileName,tData):
    pass

def writeFileInVtkFormat(fileName,triangleList):
    pass

def writeFileInPLYFormat(fileName,triangleList):
    header=[
        "ply",
        "format ascii 1.0",
        "comment made by anonymous",
        "comment this file is a test file",
        "element vertex ",
        "property float32 x",
        "property float32 y",
        "property float32 z",
        "element face ",
        "property list uint8 int32 vertex_index",
        "end_header"
    ]
    writeData=[]
    pointList=[]
    faceList=[]
    pointNum=len(pointList)
    triangleNum=len(faceList)
    for triangle in triangleList:
        if triangle.indexInList <=0:
            continue 
        else:
            tempStr=''
            tempStr+=str(triangle.aPoint.coord.x)
            tempStr+="    "
            tempStr+=str(triangle.aPoint.coord.y)
            tempStr+="    "
            tempStr+=str(triangle.aPoint.coord.z)
            pointList.append(tempStr)

            tempStr=''
            tempStr+=str(triangle.bPoint.coord.x)
            tempStr+="    "
            tempStr+=str(triangle.bPoint.coord.y)
            tempStr+="    "
            tempStr+=str(triangle.bPoint.coord.z)
            pointList.append(tempStr)

            tempStr=''
            tempStr+=str(triangle.cPoint.coord.x)
            tempStr+="    "
            tempStr+=str(triangle.cPoint.coord.y)
            tempStr+="    "
            tempStr+=str(triangle.cPoint.coord.z)
            pointList.append(tempStr)

            tempStr="3    "+str(pointNum)+"    "+str(pointNum+1)+"    "+str(pointNum+2)
            faceList.append(tempStr)
            pointNum+=3
            # if pointNum>12:
            #     break
    writeData=pointList+faceList
    pointNum=len(pointList)
    triangleNum=len(faceList)
    header[4]+=str(pointNum)
    header[8]+=str(triangleNum)
    with open(fileName,"w+") as wfpt:
        for line in header:
            wfpt.writelines(line)
            wfpt.write("\n")
        for line in writeData:
            wfpt.writelines(line)
            wfpt.write("\n")

        wfpt.close()

def changeAllStringToListBy(fileStr,char):
    res=[]
    return res

def changeLineStringToListBy(tList,char):
    res=[]
    for line in tList:
        res.append(line.split(char))
    return res

def conciseList(tList,indexList):
    res=[]
    for line in tList:
        temp=[]
        i=0
        j=0
        for x in line:
            if(i<len(indexList) and j==indexList[i]):
                i+=1
            else:
                temp.append(x)
            j+=1
        res.append(temp)
    return res

def deleteEnterChar(tList):
    res=[]
    for line in tList:
        tempLine=[]
        for x in line:
            temp=x.split('\n')
            # print("x is ",x)
            # print("temp uis ",temp)
            tempLine.append(temp[0])
        res.append(tempLine)
    return res

def main():
    print("hello world")
    fileName="./res.txt"
    # print(readFileDirect(fileName))
    print("==============================")
    res=readFileLine(fileName)
    res=changeLineStringToListBy(res,' ')
    indexList=[0,1,2,3,5]
    res=conciseList(res,indexList)
    for x in res:
        print(x)

if __name__=="__main__":
    main()

