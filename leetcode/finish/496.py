##########################################################################
# File Name: 496.py
# Author: Name
# mail: Name@qq.com
# Created Time: Tue 26 Oct 2021 11:49:04 AM CST
#########################################################################
#!/usr/bin/env python3
# coding=utf-8

class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        res=[]
        for x in nums1:
            i=0
            for i in range(0,len(nums2)):
                if nums2[i]==x:
                    break
            flag=False
            for j in range(i+1,len(nums2)):
                if nums2[j]>x:
                    res.append(nums2[j])
                    flag=True
                    break
            if not flag:
                res.append(-1)
        return res
def main():
    print("hello world")

if __name__=="__main__":
    main()

