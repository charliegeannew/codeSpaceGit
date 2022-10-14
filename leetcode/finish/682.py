##########################################################################
# File Name: 682.py
# Creat Time: 2022年03月26日 星期六 14时32分04秒
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
    def calPoints(self, ops: List[str]) -> int:
        res=0
        num=[]
        for c in ops:

            if c=='D':
                num.append(num[-1]*2)
                res+=num[-1]
            elif c=='+':
                num.append(num[-1]+num[-2])
                res+=num[-1]
            elif c=='C':
                res-=num[-1]
                num.pop(-1)

            else:
                num.append(int(c))
                res+=num[-1]
            #print(num)
        #res=sum(num)
        return res
