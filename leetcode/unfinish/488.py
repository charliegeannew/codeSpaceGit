##########################################################################
# File Name: 488.py
# Author: Charliegean
# mail: wht905@gmail.com
# Created Time: Tue 09 Nov 2021 04:56:57 PM CST
#########################################################################
#!/usr/bin/env python3
# coding=utf-8

def main():
    print("hello world")

if __name__=="__main__":
    main()
class Solution:
    def findMinStep(self, board: str, hand: str) -> int:
        res=-1
        print(board,'===',hand)
        if len(board)==0:
            res=0
        elif len(board) == 1:
            fir=-1
            sec=-1
            for j in range(len(hand)):
                if board[0]==hand[j]:
                    if fir==-1:
                        fir=j
                    elif sec==-1:
                        sec=j
                        break
            if fir!=-1 and sec!=-1:
                res=2
        elif len(hand)==0:
            res=-1
        else:
            for i in range(len(board)-1):
                if board[i]==board[i+1]:
                    fir=-1
                    for j in range(len(hand)):
                        if hand[j]==board[i]:
                            fir=j
                            break
                    if fir!=-1:
                        temp=board[:i]+board[i+2:]
                        temp=self.simpStr(temp)
                        tempHand=hand[:fir]+hand[fir+1:]
                        tempRes=self.findMinStep(temp,tempHand)
                        if tempRes!=-1:
                            if res==-1 or res>tempRes+1:
                                res=tempRes+1
                    i+=1
                else:
                    fir=-1
                    sec=-1
                    #print(hand)
                    for j in range(len(hand)):
                        if board[i]==hand[j]:
                            #print(board[i],hand[j],fir,sec)
                            if fir ==-1:
                                fir=j
                            elif sec == -1:
                                sec=j
                                break 
                    if fir != -1 and sec!=-1:
                        temp=board[:i]+board[i+1:]
                        temp=self.simpStr(temp)
                        tempHand=hand[:fir]+hand[fir+1:sec]+hand[sec+1:]
                        tempRes=self.findMinStep(temp,tempHand)
                        if tempRes!=-1:
                            flag=True
                            if res==-1 or res>tempRes+1:
                                res=tempRes+2  
            if board[-1]!=board[-2]:
                fir=-1
                sec=-1
                for j in range(len(hand)):
                    if board[-1]==hand[j]:
                        if fir ==-1:
                            fir=j
                        elif sec == -1:
                            sec=j
                            break 
                if fir != -1 and sec!=-1:
                    temp=board[:-1]
                    #temp.self.simpStr(temp)
                    tempHand=hand[:fir]+hand[fir+1:sec]+hand[sec+1:]
                    tempRes=self.findMinStep(temp,tempHand)
                    if tempRes!=-1:
                        flag=True
                        if res==-1 or res>tempRes+1:
                            res=tempRes+2  
            #if not flag:
             #   res=-1
            #print(res)
        return res 

    def simpStr(self,string:str)->str:
        if len(string)>2:
            i=0
            while i<=len(string)-2:
                j=i+1
                while string[i]==string[j]:
                    j+=1
                    if j==len(string):
                        break
                if j-i>2:
                    string=string[:i]+string[j:]
                    i=0
                else:
                    i=j
        return string
