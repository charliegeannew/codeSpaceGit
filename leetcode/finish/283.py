##########################################################################
# File Name: 283.py
# Author: Name
# mail: Name@qq.com
# Created Time: Sun 24 Oct 2021 05:04:36 PM CST
#########################################################################
#!/usr/bin/env python3
# coding=utf-8

class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        zeroIndex=-1
        numIndex=-1
        for i in range(0,len(nums)):

            if nums[i] == 0:
                if zeroIndex==-1:
                    zeroIndex=i
                elif i <zeroIndex:
                    zeroIndex=i
            else:
                numIndex=i

            #print(nums)
            #print(i,zeroIndex,numIndex)
            if zeroIndex>-1 and numIndex>-1 and numIndex>zeroIndex:
                nums[zeroIndex]=nums[numIndex]
                nums[numIndex]=0
                for j in range(zeroIndex,numIndex+1):
                    if nums[j]==0:
                        zeroIndex=j
                        break
                numIndex=-1
def main():
    print("hello world")

if __name__=="__main__":
    main()

