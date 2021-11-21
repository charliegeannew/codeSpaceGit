##########################################################################
# File Name: 299.py
# Author: Charliegean
# mail: wht905@gmail.com
# Created Time: Mon 08 Nov 2021 02:27:03 PM CST
#########################################################################
#!/usr/bin/env python3
# coding=utf-8
class Solution:
    def getHint(self, secret: str, guess: str) -> str:
        res=''
        sec=[0 for i in range(10)]
        gue=[0 for i in range(10)]
        a=0
        b=0
        for i in range(len(secret)):
            if secret[i]==guess[i]:
                a+=1
            else:
                sec[int(secret[i])]+=1
                gue[int(guess[i])] +=1
        for i in range(10):

            b+=min(sec[i],gue[i])
        res=str(a)+'A'+str(b) +'B'
        return res
def main():
    print("hello world")

if __name__=="__main__":
    main()

