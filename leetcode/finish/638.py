##########################################################################
# File Name: 638.py
# Author: Name
# mail: Name@qq.com
# Created Time: Sun 24 Oct 2021 04:40:00 PM CST
#########################################################################
#!/usr/bin/env python3
# coding=utf-8

class Solution:
    def shoppingOffers(self, price: List[int], special: List[List[int]], needs: List[int]) -> int:
        res=0
        tempRes=0
        flag=False
        flagIndex=-1
        for i in range(0,len(price)):
            if price[i]==0:
                needs[i]=0
        for i in range(0,len(needs)):
            if needs[i]>0:
                flag=True
        if flag:
            for j in range(0,len(special)):
                tempFalg=True
                tempNeeds=needs.copy()
                for i in range(0,len(needs)):
                    if tempNeeds[i]<special[j][i]:
                        tempFalg=False
                tempRes=0
                if tempFalg:
                    for i in range(0,len(needs)):
                        tempNeeds[i]-=special[j][i]
                    tempRes=special[j][-1]+self.shoppingOffers(price,special,tempNeeds)
                    noSpecialRes=0
                    for i in range(0,len(needs)):
                        noSpecialRes+=(needs[i]*price[i])
                    if tempRes>noSpecialRes:
                        tempRes=noSpecialRes
                        flagIndex=-2
                    print("tempRes,res,special === ",tempRes,res,special[j][-1])
                    if res==0 and flagIndex==-1:
                        res=tempRes
                        flagIndex=j
                    elif res>tempRes:
                        res=tempRes
                        flagIndex=j
                    elif flagIndex==-2:
                        if res==0:
                            res=tempRes
                        elif res>tempRes:
                            res=tempRes
            if flagIndex==-1:
                for i in  range(0,len(needs)):
                    res+=needs[i]*price[i]
        else:
            res=0
        print("in end res is ",res)
        return res

def main():
    print("hello world")

if __name__=="__main__":
    main()

