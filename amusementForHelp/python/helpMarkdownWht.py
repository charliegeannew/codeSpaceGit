##########################################################################
# File Name: helpMarkdown.py
# Author: Charliegean
# mail:wht905@gmail.com
# Created Time: Fri Jul  9 23:48:23 2021
#########################################################################
#!/usr/bin/env python3
# coding=utf-8
import readFileWht as rfw

def changeStrListToTable(tList):
    res=[]
    # print(tList)
    for line in tList:
        temp='|'
        for x in line:
            temp+=str(x)+'|'
        res.append(temp)
    return res

def mergeStrList(tList,indexList):#indexList's len >= 2
    res=[]
    for line in tList:
        tempLine=[]
        for i in range(0,len(indexList)-1):
            beginIndex=indexList[i]
            endIndex=indexList[i+1]
            if beginIndex>endIndex:
                endIndex=len(line)
            temp=''
            for j in range(beginIndex,endIndex):
                temp+=line[j]+' '
            tempLine.append(temp)
        res.append(tempLine)
    return res

def addTableHeader(n):
    res=''
    return res

def main():
    print("hello world")
    fileName="./res.txt"
    res=rfw.readFileLine(fileName)
    res=rfw.changeLineStringToListBy(res,' ')
    res=rfw.deleteEnterChar(res)
    deleteIndexList=[0,1,2,3,5]
    res=rfw.conciseList(res,deleteIndexList)
    mergeIndex=[0,1,0]
    res=mergeStrList(res,mergeIndex)
    res=changeStrListToTable(res)
    for x in res:
        print(x)

if __name__=="__main__":
    main()

