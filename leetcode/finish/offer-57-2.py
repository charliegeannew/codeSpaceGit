#!/usr/bin/env python
# coding=utf-8
class Solution:
    def findContinuousSequence(self, target: int) -> List[List[int]]:
        res=[]
        if target>2:
            for i in range(int((target*2+0.25)**0.5-0.5),1,-1):
                temp=target-i*(i-1)/2
                if temp%i==0:
                    res.append([x for x in range(int(temp/i),int(temp/i)+i)])
        return res 
