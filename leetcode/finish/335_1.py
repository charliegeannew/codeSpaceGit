#!/usr/bin/env python
# coding=utf-8
class Solution:
    def isSelfCrossing(self, distance: List[int]) -> bool:
        res=False
        dic={}
        dic[0]={"beg":[0],"end":[distance[0]]}
        nowCoord=[0,distance[0]]
        for i in range(1,len(distance)):
            if i%4==0:
                if nowCoord[0] in dic:
                    for j in range(0,len(dic[nowCoord[0]]["beg"])):
                        if (dic[nowCoord[0]]["beg"][j]<=nowCoord[1]+distance[i] and dic[nowCoord[0]]["beg"][j]>=nowCoord[1]+1) or (dic[nowCoord[0]]["end"][j]<=nowCoord[1]+distance[i] and dic[nowCoord[0]]["end"][j]>=nowCoord[1]+1):
                            res=True
                            break       
                else:
                    dic[nowCoord[0]]={"beg":[nowCoord[1]],"end":[nowCoord[1]]}
                if res:
                    break
                else:
                    dic[nowCoord[0]]["beg"].append(nowCoord[1])
                    dic[nowCoord[0]]["end"].append(nowCoord[1]+distance[i])
                nowCoord[1]+=distance[i]
            elif i%4==1:
                for j in range(1,distance[i]+1):
                    if nowCoord[0]-j in dic:
                        
                        for k in range(0,len(dic[nowCoord[0]-j]["beg"])):
                            if nowCoord[1]<=dic[nowCoord[0]-j]["end"][k] and nowCoord[1]>=dic[nowCoord[0]-j]["beg"][k]:
                                res=True
                                break
                        if res:
                            break
                        else:
                            dic[nowCoord[0]-j]["beg"].append(nowCoord[1])
                            dic[nowCoord[0]-j]["end"].append(nowCoord[1])
                    else:
                        dic[nowCoord[0]-j]={'beg':[nowCoord[1]],"end":[nowCoord[1]]}
                nowCoord[0]-=distance[i]
            elif i%4==2:
                if nowCoord[0] in dic:
                    for j in range(0,len(dic[nowCoord[0]]["beg"])):
                        if (dic[nowCoord[0]]["beg"][j]>=nowCoord[1]-distance[i] and dic[nowCoord[0]]["beg"][j]<=nowCoord[1]-1) or (dic[nowCoord[0]]["end"][j]>=nowCoord[1]-distance[i] and dic[nowCoord[0]]["end"][j]<=nowCoord[1]-1):
                            res=True
                            break        
                else:
                    dic[nowCoord[0]]={"beg":[nowCoord[1]],"end":[nowCoord[1]]}
                
                if res:
                    break
                else:
                    dic[nowCoord[0]]["end"].append(nowCoord[1])
                    dic[nowCoord[0]]["beg"].append(nowCoord[1]-distance[i]) 
                nowCoord[1]-=distance[i]
            elif i%4==3:
                for j in range(1,distance[i]+1):
                    if nowCoord[0]+j in dic:
                        for k in range(0,len(dic[nowCoord[0]+j]["beg"])):
                            if nowCoord[1]<=dic[nowCoord[0]+j]["end"][k] and nowCoord[1]>=dic[nowCoord[0]+j]["beg"][k]:
                                res=True
                                break
                        if res:
                            pass
                        else:
                            dic[nowCoord[0]+j]["beg"].append(nowCoord[1])
                            dic[nowCoord[0]+j]["end"].append(nowCoord[1])
                    else:
                        dic[nowCoord[0]+j]={'beg':[nowCoord[1]],"end":[nowCoord[1]]}
                    if res:
                        break 
                nowCoord[0]+=distance[i]

            #print(i)
            #print(nowCoord)
            #print(dic)
            if res:
                break
        return res 
