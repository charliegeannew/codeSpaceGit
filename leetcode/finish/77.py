##########################################################################
# File Name: 77.py
# Author: Charliegean
# mail: wht905@gmail.com
# Created Time: Mon 27 Dec 2021 04:20:47 PM CST
#########################################################################
#!/usr/bin/env python3
# coding=utf-8

def main():
    print("hello world")

if __name__=="__main__":
    main()
class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        res=[[i+1] for i in range(n-k+1)]
        k-=1
        #print(res)
        while k>0:
            m=len(res[0])
            for i in range(len(res)):
                if len(res[i])==m:
                    if res[i][-1]<n-k+1:
                        res[i].append(res[i][-1]+1)
                        for j in range(res[i][-2]+2,n-k+2):
                            temp=res[i].copy()
                            temp[-1]=j
                            res.append(temp)
                    
            k-=1
        return res 
