##########################################################################
# File Name: 172.py
# Creat Time: 2022年03月26日 星期六 14时31分12秒
# Author :Charliegean
# Mail :wht905@gmail.com
##########################################################################
#!/usr/bin/env python3
# coding=utf-8

def main():
    print("hello world")

if __name__=="__main__":
    main()

class Solution:
    def trailingZeroes(self, n: int) -> int:
        res=0
        m=5
        while m<=n:
            res+=int(n/m)
            m*=5
        return res
