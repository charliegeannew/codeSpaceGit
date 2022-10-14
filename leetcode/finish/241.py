##########################################################################
# File Name: 241.py
# Author: Charliegean
# mail: wht905@gmail.com
# Created Time: Fri Jul  1 12:07:45 2022
#########################################################################
#!/usr/bin/env python3
# coding=utf-8
class Solution:
    def diffWaysToCompute(self, expression: str) -> List[int]:
        res=[]
        dic=[]
        expList=[]
        temp=''
        for c in expression:
            if c=='+' or c=='-' or c=='*' or c=='/':
                expList.append(int(temp))
                expList.append(c)
                temp=''
            else:
                temp+=c
        print()
        return res 
    class Solution:
    def diffWaysToCompute(self, expression: str) -> List[int]:
        res=[]
        res=[]
        dic=[]
        expList=[]
        numList=[]
        opsList=[]
        temp=''
        for c in expression:
            if c=='+' or c=='-' or c=='*':
                expList.append(int(temp))
                numList.append(int(temp))
                opsList.append(c)
                expList.append(c)
                temp=''
            else:
                temp+=c
        expList.append(int(temp))
        numList.append(int(temp))
        #print(expList)
        self.dic={}
        res=self.calRes(numList,opsList)
        return res

    dic={}

    def calRes(self,numList,opsList):
        #print(numList,opsList)
        s=self.changeStr(numList,opsList)
        if s in self.dic:
            return self.dic[s]

        elif len(opsList)==0:

            res=[numList[0]]
        elif len(opsList)==1:
            if opsList[0]=='+':
                res=[numList[0]+numList[1]]
            elif opsList[0]=='-':
                res=[numList[0]-numList[1]]
            elif opsList[0]=='*':
                res=[numList[0]*numList[1]]
        else:
            res=[]
            for i in range(0,len(opsList)):
                lef=self.calRes(numList[:i+1],opsList[:i])
                rig=self.calRes(numList[i+1:],opsList[i+1:])

                for j in range(0,len(lef)):
                    for k in range(len(rig)):
                        if opsList[i]=='+':
                            res.append(lef[j]+rig[k])
                        elif  opsList[i]=='-':
                            res.append(lef[j]-rig[k])
                        elif  opsList[i]=='*':
                            res.append(lef[j]*rig[k])
        #print("cal res ",res)
        self.dic[s]=res
        return res
    def changeStr(self,numList,opsList):
        res=''
        i=0
        j=0
        while True:
            if i<len(numList):
                res+=str(numList[i])
            if j<len(opsList):
                res+=str(opsList[j])
            i+=1
            j+=1
            if i>=len(numList) and j>=len(opsList):
                break
        return res
def main():
    print("hello world")

if __name__=="__main__":
    main()

