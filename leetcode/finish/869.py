#!/usr/bin/env python
# coding=utf-8
class Solution:
    def reorderedPowerOf2(self, n: int) -> bool:
        res=True
        s=str(n)
        sIn=int(math.log(10**(len(s)-1),2))
        lIn=int(math.log(10**(len(s)),2))+1
        dic=[0 for i in range(0,10)]
        for c in s:
            dic[int(c)]+=1
        for i in range(sIn,lIn+1):
            temp=str(2**i)
            if len(temp)!=len(s):
                continue
            tempDic=dic.copy()
            for c in temp:
                tempDic[int(c)]-=1
            res=True
            for j in tempDic:
                if j!=0:
                    res=False
                    break
            if res:
                break
        return res
