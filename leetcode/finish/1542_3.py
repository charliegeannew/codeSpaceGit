#!/usr/bin/env python
# coding=utf-8
class Solution:
    def longestAwesome(self, s: str) -> int:
        res=0
        if len(s)<=1:
            res=len(s)
        else:
            oddList={}
            pre=0
            oddList[0]=-1
            for i in range(0,len(s)):
                sta=pre^(1<<int(s[i]))
                if sta in oddList:
                    if res<i-oddList[sta]:
                        res=i-oddList[sta]
                else:
                    oddList[sta]=i
                for j in range(0,10):
                    sigsta=sta^(1<<j)
                    if sigsta in oddList:
                        if res<i-oddList[sigsta]:
                            res=i-oddList[sigsta]
                pre=sta 
        return res

