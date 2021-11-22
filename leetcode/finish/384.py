##########################################################################
# File Name: finish/384.py
# Author: Charliegean
# mail: wht905@gmail.com
# Created Time: Mon Nov 22 00:21:05 2021
#########################################################################
#!/usr/bin/env python3
# coding=utf-8
class Solution:

    def __init__(self, nums: List[int]):
        self.nums=nums.copy()
        self.begnums=nums.copy()


    def reset(self) -> List[int]:
        return self.begnums


    def shuffle(self) -> List[int]:
        import random
        if len(self.begnums)==1:
            return self.begnums
        else:
            for i in range(len(self.nums)):
                ind=random.randint(i,len(self.nums)-1)
                temp=self.nums[i]
                self.nums[i]=self.nums[ind]
                self.nums[ind]=temp
            return self.nums




# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.reset()
# param_2 = obj.shuffle()