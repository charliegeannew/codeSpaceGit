##########################################################################
# File Name: 1442.py
# Author: Name
# mail: Name@qq.com
# Created Time: Sat 23 Oct 2021 03:19:09 PM CST
#########################################################################
#!/usr/bin/env python3
# coding=utf-8

class Solution:
    def countTriplets(self, arr: List[int]) -> int:
        res=0
        flag=[]
        for i in range(0,len(arr)):
            temp=[]
            for j in range(0,i):
                temp.append(0)
            temp.append(arr[i])
            for j in range(i+1,len(arr)):
                temp.append(temp[j-1]^arr[j])
            flag.append(temp)
        for j in range(1,len(arr)):
            for i in range(0,j):
                for k in range(j,len(arr)):
                    if (flag[i][j-1]==flag[j][k]):
                        res+=1
        return res
def main():
    print("hello world")

if __name__=="__main__":
    main()

