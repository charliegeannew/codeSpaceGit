##########################################################################
# File Name: 1840.py
# Author: Charliegean
# mail: wht905@gmail.com
# Created Time: Sat 06 Nov 2021 10:03:22 PM CST
#########################################################################
#!/usr/bin/env python3
# coding=utf-8

def main():
    print("hello world")

if __name__=="__main__":
    main()
class Solution:
    def maxBuilding(self, n: int, restrictions: List[List[int]]) -> int:
        res=0
        minDic=[-1 for i in range(n)]
        maxDic=[-1 for i in range(n)]
        minDic[0]=0
        maxDic[0]=0
        for x in restrictions:
            maxDic[x[0]-1]=x[1]
        for i in range(2,n+1):
            if maxDic[i-1]==-1:
                maxDic[i-1]=maxDic[i-2]+1
            elif maxDic[i-1]>maxDic[i-2]+1:
                maxDic[i-1]=maxDic[i-2]+1
            if minDic[i-1]==-1:
                if minDic[i-2]>0:
                    minDic[i-1]=minDic[i-2]-1
                else:
                    minDic[i-1]=0
            elif minDic[i-1]<minDic[i-2]-1:
                minDic[i-1]=minDic[i-2]-1
        for i in range(n-1,2,-1):
            if maxDic[i-1]==-1:
                maxDic[i-1]=maxDic[i]+1
            elif maxDic[i-1]>maxDic[i]+1:
                maxDic[i-1]=maxDic[i]+1
            if minDic[i-1]==-1:
                if minDic[i-2]>0:
                    minDic[i-1]=minDic[i]-1
                else:
                    minDic[i-1]=0
            elif minDic[i-1]<minDic[i]-1:
                minDic[i-1]=minDic[i]-1
        res=max(maxDic)

        return res 
