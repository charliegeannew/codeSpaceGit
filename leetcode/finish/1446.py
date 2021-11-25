##########################################################################
# File Name: 1446.py
# Author: Charliegean
# mail: wht905@gmail.com
# Created Time: Thu 25 Nov 2021 03:16:43 PM CST
#########################################################################
#!/usr/bin/env python3
# coding=utf-8

def main():
    print("hello world")

if __name__=="__main__":
    main()
class Solution:
    def maxPower(self, s: str) -> int:
        res=1
        for i in range(len(s)):
            for j in range(i+1,len(s)):
                if s[i]==s[j]:
                    if res<j-i+1:
                        res=j-i+1
                else:
                    break
        return res 
