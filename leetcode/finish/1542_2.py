#!/usr/bin/env python
# coding=utf-8
class Solution:
    def longestAwesome(self, s: str) -> int:
        res=1
        if len(s)<=1:
            res=len(s)
        else:
            oddList=[]
            for i in range(0,len(s)):
                oddList.append(1<<int(s[i]))
            res=1
            for i in range(1,len(s)):
                temp=1<<int(s[i])
                for j in range(0,i):
                    oddList[j]=oddList[j]^temp
                    if bin(oddList[j]).count('1')<=1 and res<i-j+1:
                        res=i-j+1

        return res
