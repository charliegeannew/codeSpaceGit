##########################################################################
# File Name: 458.py
# Author: Charliegean
# mail: wht905@gmail.com
# Created Time: Thu 25 Nov 2021 03:12:12 PM CST
#########################################################################
#!/usr/bin/env python3
# coding=utf-8
class Solution:
    def poorPigs(self, buckets: int, minutesToDie: int, minutesToTest: int) -> int:
        res=0
        ind=int(minutesToTest/minutesToDie)+1
        import math
        res=math.log(buckets,ind)
        #print(res)
        res=ceil(res)
        return res
def main():
    print("hello world")

if __name__=="__main__":
    main()

