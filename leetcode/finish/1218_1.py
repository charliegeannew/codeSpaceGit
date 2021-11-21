##########################################################################
# File Name: 1218.py
# Author: Charliegean
# mail: wht905@gmail.com
# Created Time: Fri 05 Nov 2021 12:18:46 PM CST
#########################################################################
#!/usr/bin/env python3
# coding=utf-8
class Solution:
    def longestSubsequence(self, arr,difference):
        res=0
        dic={}
        for i in range(0,len(arr)):
            if arr[i] in dic:
                dic[arr[i]].append(i)
            else:
                dic[arr[i]]=[i]
        print(dic)
        for i in range(0,len(arr)):
            tempL=1
            tempi=i 
            flag=False
            while True:
                if (arr[tempi] + difference) in dic:
                    for j in dic[arr[tempi]+difference]:
                        print(j)
                        if j>tempi:
                            tempi=j
                            tempL+=1
                            flag=True 
                            break
                    # if tempL==1 or tempi != i:
                    #     break 
                    if flag:
                        break 
                else:
                    break
            print("===",tempL,res)
            if res<tempL:
                res=tempL
        return res 
def main():
    print("hello world")
    arr=[1,2,3,4]
    dif=1
    # arr=[-6,6,-8,0,-8,5,-7,10,-10]
    # dif=-6
    sol=Solution()
    print(sol.longestSubsequence(arr,dif))

if __name__=="__main__":
    main()

