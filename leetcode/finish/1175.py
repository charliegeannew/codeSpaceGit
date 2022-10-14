##########################################################################
# File Name: 1175.py
# Author: Charliegean
# mail: wht905@gmail.com
# Created Time: Thu Jun 30 22:12:12 2022
#########################################################################
#!/usr/bin/env python3
# coding=utf-8

class Solution:
    def numPrimeArrangements(self, n: int) -> int:
        primeList=[]
        res=0
        if n==1:
            res=1
        elif n==2:
            res=1
        else:
            primeList=[2]
            for i in range(3,n+1,2):
                flag=False
                for prime in primeList:
                    if i%prime==0:
                        flag=True
                        break
                if not flag:
                    primeList.append(i)
            #print(primeList)
            primeN=len(primeList)
            compositeN=n-primeN
            primeRes = 1
            compositeRes = 1
            k=int(10e8+7)
            for i in range(1,min(primeN,compositeN)+1):
                primeRes=primeRes*i
                primeRes=int(primeRes)%(k)
                primeRes=int(primeRes)
            compositeRes=1
            for i in range(2,max(primeN,compositeN)+1):
                compositeRes*=i
                compositeRes=int(compositeRes)%(k)
                compositeRes=int(compositeRes)
            # print(n,primeN,compositeN,primeRes,compositeRes)
            res=primeRes*compositeRes
            res=int(res)%(k)
        return res

def main():
    print("hello world")
    sol=Solution()
    # print(100%(10e8+7))
    for i in range(1,101):
        print(i,sol.numPrimeArrangements(i))
    # print(10e9,10**9)

if __name__=="__main__":
    main()

