#!/usr/bin/env python
# coding=utf-8
class Solution:
    def isSelfCrossing(self, distance: List[int]) -> bool:
        res=False
        dic={}
        dic[0]=[0]
        i=0
        nowCoord=[0,0]
        for point in distance:
            if i%4==0:
                for j in range(1,point+1):
                    if not nowCoord[0] in dic:
                        dic[nowCoord[0]]=[nowCoord[1]+j]
                    elif nowCoord[1]+j in dic[nowCoord[0]]:
                        res=True 
                        break
                    else:
                        dic[nowCoord[0]].append(nowCoord[1]+j)
                nowCoord[1]+=point 
            elif i%4==1:
                for j in range(1,point+1):
                    if not nowCoord[0]-j in dic:
                        dic[nowCoord[0]-j]=[nowCoord[1]]
                    elif nowCoord[1] in dic[nowCoord[0]-j]:
                        res=True 
                        break
                    else:
                        dic[nowCoord[0]-j].append(nowCoord[1])
                nowCoord[0]-=point
            elif i%4==2:
                for j in range(1,point+1):
                    if not nowCoord[0] in dic:
                        dic[nowCoord[0]]=[nowCoord[1]+j]
                    elif nowCoord[1]-j in dic[nowCoord[0]]:
                        res=True 
                        break
                    else:
                        dic[nowCoord[0]].append(nowCoord[1]-j)
                nowCoord[1]-=point 
            elif i%4==3:
                for j in range(1,point+1):
                    if not nowCoord[0]+j in dic:
                        dic[nowCoord[0]+j]=[nowCoord[1]]
                    elif nowCoord[1] in dic[nowCoord[0]+j]:
                        res=True 
                        break
                    else:
                        dic[nowCoord[0]+j].append(nowCoord[1])
                nowCoord[0]+=point
            i +=1
            #print(nowCoord)
            if res:
                break
        return res 
