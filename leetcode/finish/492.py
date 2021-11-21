##########################################################################
# File Name: 492.py
# Author: Name
# mail: Name@qq.com
# Created Time: Sat 23 Oct 2021 03:18:29 PM CST
#########################################################################
#!/usr/bin/env python3
# coding=utf-8

class Solution:
    def constructRectangle(self, area: int) -> List[int]:
        res=[]
        L=int(area**0.5)
        W=int(area/L)
        while True:
            print(L,W)
            if(L==1):
                res.append(area)
                res.append(L)
                break
            if(L*W==area):
                res.append(W)
                res.append(L)
                break
            else:
                L-=1
                W=int(area/L)
        return res
def main():
    print("hello world")

if __name__=="__main__":
    main()

