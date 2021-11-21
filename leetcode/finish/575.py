#!/usr/bin/env python
# coding=utf-8
class Solution:
    def distributeCandies(self, candyType: List[int]) -> int:
        res=0
        dic={}
        for can in candyType:
            if can in dic:
                continue
            else:
                dic[can]=0
        if len(dic)>=len(candyType)/2:
            res=int(len(candyType)/2)
        else:
            res=len(dic)
        return res 
