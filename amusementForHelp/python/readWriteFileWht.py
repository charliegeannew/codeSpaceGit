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

