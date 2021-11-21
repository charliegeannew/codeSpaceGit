##########################################################################
# File Name: 866.py
# Creat Time: 2021年10月17日 星期日 16时07分08秒
# Author :Charliegean
# Mail :wht905@gmail.com
##########################################################################
#!/usr/bin/env python3
# coding=utf-8

class Solution:
    def __init__(self,n=-1):
        self.n=n

    def primePalindrome(self,n:int)->int:
        if(n%2==0):
            res=n+1
        else:
            res=n+2
        # while((not self.ifPrime(res)) and (not self.ifPalindrome(res))):
        while((not self.ifPrime(res)) or (not self.ifPalindrome(res))):
            res+=2
        return res
    def ifPrime(self,n:int)->bool:
        flag=True
        # print("n===",n)
        if(n%2==0):
            flag=False 
        else:
            for i in range(3,int(n**0.5)+1,2):
                if(n%i==0):
                    flag=False
                    break 
        if(n==2 or n==3):
            flag=True 
        return flag 
    def ifPalindrome(self,n:int)->bool:
        flag=True
        minIndex=0
        numStr=str(n)
        maxIndex=len(numStr)
        maxIndex-=1
        # print(numStr)
        # print(minIndex,"\t",maxIndex)
        while(True):
            if(numStr[minIndex]!=numStr[maxIndex]):
                flag=False
                break
            elif(minIndex>=maxIndex):
                break
            minIndex+=1
            maxIndex-=1
        return flag

def main():
    print("hello world")
    sol=Solution(8)
    print(sol.ifPrime(49))
    print(sol.ifPalindrome(51234215))
    print(sol.primePalindrome(13))

if __name__=="__main__":
    main()

