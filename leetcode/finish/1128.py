#!/usr/bin/env python
# coding=utf-8
class Solution:
    def numEquivDominoPairs(self, dominoes: List[List[int]]) -> int:
        dic=[[0 for i in range(0,9)] for j in range(0,9)]
        res=0
        for dom in dominoes:
            dic[dom[0]-1][dom[1]-1]+=1
        #for line in dic:
         #   print(line)
        for i in range(0,9):
            res+=int(dic[i][i]*(dic[i][i]-1)/2)
            for j in range(i+1,9):
                res+=int((dic[i][j]+dic[j][i])*(dic[i][j]+dic[j][i]-1)/2)

        return res 
