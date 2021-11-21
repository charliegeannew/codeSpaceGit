#!/usr/bin/env python
# coding=utf-8
class Solution:
    def longestAwesome(self, s: str) -> int:
        res=1
        if len(s)<=1:
            res=len(s)
        else:

            dic={"0":0,"1":0, "2":0,"3":0,"4":0,"5":0,"6":0,"7":0,"8":0,"9":0,"odd":0}
            #oddList=[dic for i in range(0,len(s))]
            oddList=[]
            for i in range(0,len(s)):
                tempDic=dic.copy()
                tempDic[s[i]]+=1
                tempDic["odd"]+=1
                oddList.append(tempDic)
            res=1
            for i in range(1,len(s)):
                for j in range(0,i):
                    if oddList[j][s[i]]%2==1:
                        oddList[j]["odd"]-=1
                    else:
                        oddList[j]["odd"]+=1  
                    oddList[j][s[i]]+=1
                    #print("i,j === ",i,j)
                    #for tempDic in oddList:
                      #  print(tempDic)
                    if oddList[j]["odd"]<=1 and res<i-j+1:
                        res=i-j+1

        return res


    def ifAwesome(self,s:str)->int:
        res=1
        if len(s)<=1:
            res=1
        else:
            dic={
                "0":0,
                "1":0,
                "2":0,
                "3":0,
                "4":0,
                "5":0,
                "6":0,
                "7":0,
                "8":0,
                "9":0
            }
            for i in range(0,len(s)):
                dic[s[i]]+=1
            oddNum=0
            for key in dic:
                if dic[key]%2==1:
                    oddNum+=1
                    if oddNum>1:
                        res=0
                        break
        #print(s)
        #print("res is ",res)
        return res
