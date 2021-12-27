##########################################################################
# File Name: 825.py
# Author: Charliegean
# mail: wht905@gmail.com
# Created Time: Mon 27 Dec 2021 04:01:07 PM CST
#########################################################################
#!/usr/bin/env python3
# coding=utf-8

def main():
    print("hello world")

if __name__=="__main__":
    main()
class Solution:
    def numFriendRequests(self, ages: List[int]) -> int:
        dic={}
        for x in ages:
            if x>=15:
                if x in dic:
                    dic[x]+=1
                else:
                    dic[x]=1
        ages=[]
        res=0
        for key in dic:
            ages.append(key)
            res+=int(dic[key]*(dic[key]-1))
        ages.sort()
        n=len(ages)
        
        for i in range(n-1,0,-1):
            #print("i=== ",i,res)
            for j in range(i-1,-1,-1):
                if ages[j]>ages[i]/2+7:
                    res+=dic[ages[j]]*dic[ages[i]]
                else:
                    break
            #print("i=== ",i,res)
        return res
