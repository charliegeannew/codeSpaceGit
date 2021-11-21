##########################################################################
# File Name: 1840.py
# Author: Charliegean
# mail: wht905@gmail.com
# Created Time: Sat 06 Nov 2021 10:03:22 PM CST
#########################################################################
#!/usr/bin/env python3
# coding=utf-8
class Solution:
    def maxBuilding(self, n: int, restrictions: List[List[int]]) -> int:
        res=0
        import queue
        dic=queue.PriorityQueue()
        for x in restrictions:
            dic.put(x)
        dic.put([n,n-1])
        ddic=queue.PriorityQueue()
        ddic.put([n-1,0])
        bef=[1,0]
        while not dic.empty():
            now=dic.get()
            flag=False
            if now[0] - bef[0] >= now[1]-bef[1]:
                ddic.put([n-now[0],now[1]])
                bef=now
        bef=ddic.get()
        if bef[0]!=0:
            res=bef[0]+bef[1]
        while not ddic.empty():
            now=ddic.get()
            if now[0]-bef[0] < now[1]-bef[1]:
                continue
            else:
                midm=int((now[0]+bef[0]+now[1]-bef[1])/2-bef[0]+bef[1])
                res=max(midm,res)
            bef=now
        return res 
def main():
    print("hello world")
if __name__=="__main__":
    main()
