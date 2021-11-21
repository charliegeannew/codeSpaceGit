##########################################################################
# File Name: 392.py
# Author: Name
# mail: Name@qq.com
# Created Time: Mon 25 Oct 2021 09:22:31 PM CST
#########################################################################
#!/usr/bin/env python3
# coding=utf-8

class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        res=False
        if len(s)==0:
            res=True
        else:
            if len(t)==0:
                res=False
            else:

                sIndex=0
                tIndex=0
                while True:

                    if sIndex>=len(s):
                        break
                    if tIndex>=len(t):
                        break
                    #print(s[sIndex],t[tIndex])
                    if s[sIndex]==t[tIndex]:

                        sIndex+=1
                        tIndex+=1
                    else:
                        tIndex+=1
                if sIndex==len(s):
                    res=True
        return res
def main():
    print("hello world")

if __name__=="__main__":
    main()

