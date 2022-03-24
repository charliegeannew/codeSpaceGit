##########################################################################
# File Name: 1104.py
# Creat Time: 2022年03月24日 星期四 21时08分20秒
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
    def pathInZigZagTree(self, label: int) -> List[int]:
        import math
        hang = int(math.log(label,2))
        res=[]
        if label>1:
            temp=label
            for i in range(hang,-1,-1):

                if i%2==0:
                    res.append(temp)
                    temp=int(math.pow(2,i-1))*3-int(temp/2)-1
                else:
                    realNum=int(math.pow(2,i)*3)-temp-1
                    res.append(temp)
                    temp=int(realNum/2)
               # print(temp,i,realNum)
            for i in range(0,int(len(res)/2)):
                temp=res[i]
                res[i]=res[len(res)-1-i]
                res[len(res)-1-i]=temp
        else:
            res=[1]
        return res

