#!/usr/bin/env python
# coding=utf-8
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        res=''
        ai=len(a)-1
        bi=len(b)-1
        temp=0
        while True:
            res=str((int(a[ai])+int(b[bi])+temp)%2)+res
            temp=int((int(a[ai])+int(b[bi])+temp)/2)
            ai-=1
            bi-=1
            if ai <0:
                break
            if bi<0:
                break
        while ai >=0:
            res=str((int(a[ai])+temp)%2)+res
            temp=int((int(a[ai])+temp)/2)
            ai-=1
        while bi >=0:
            res=str((int(b[bi])+temp)%2)+res
            temp=int((int(b[bi])+temp)/2)
            bi-=1
        if temp == 1:
            res='1'+res
        return res 
