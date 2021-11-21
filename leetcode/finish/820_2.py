##########################################################################
# File Name: 820_2.py
# Author: Name
# mail: Name@qq.com
# Created Time: Wed 27 Oct 2021 04:10:32 PM CST
#########################################################################
#!/usr/bin/env python3
# coding=utf-8

class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        res=0
        temp=[]
        for word in words:
            flag=True
            for i in range(0,len(temp)):
                if len(temp[i])>=len(word):
                    if temp[i][len(temp[i])-len(word):]==word:
                        flag=False
                        break
                else:
                    if word[len(word)-len(temp[i]):]==temp[i]:
                        flag=False
                        temp[i]=word
                        break
            if flag:
                temp.append(word)
        for t in temp:
            res+=len(t)+1
        return res
def main():
    print("hello world")

if __name__=="__main__":
    main()

