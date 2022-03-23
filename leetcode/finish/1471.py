##########################################################################
# File Name: 1471.py
# Creat Time: 2022年03月23日 星期三 18时11分05秒
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
    def getStrongest(self, arr: List[int], k: int) -> List[int]:
        arr.sort()
        m=arr[int((len(arr)-1)/2)]
        bInd=0
        eInd=len(arr)-1
        res=[]
        while len(res)<k:
            if arr[eInd]-m>=m-arr[bInd]:
                res.append(arr[eInd])
                eInd-=1
            else:
                res.append(arr[bInd])
                bInd+=1
        return res
