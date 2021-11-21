#!/usr/bin/env python
# coding=utf-8
class Solution:
    def findWords(self, words: List[str]) -> List[str]:
        res=[]
        fir = "qwertyuiopQWERTYUIOP"
        sec = "asdfghhjklASDFGHJKL"
        thir = "zxcvbnmZXCVBNM"
        for word in words:
            flag=-1
            for c in word:
                if c in fir:
                    if flag==-1:
                        flag=0
                    elif flag!=0:
                        flag=4
                        break
                if c in sec:
                    if flag == -1:
                        flag=1
                    elif flag!=1:
                        flag=4
                        break
                if c in thir:
                    if flag == -1:
                        flag=2
                    elif flag!=2:
                        flag=4
                        break
            if flag==4:
                continue
            else:
                res.append(word)
        return res
