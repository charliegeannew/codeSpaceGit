##########################################################################
# File Name: 820_1.py
# Author: Name
# mail: Name@qq.com
# Created Time: Wed 27 Oct 2021 03:57:47 PM CST
#########################################################################
#!/usr/bin/env python3
# coding=utf-8

class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        res=0
        s=''

        for word in words:
            if len(s)==0:
                s=s+word+'#'
            else:
                sSplitList=s.split('#')
                sSplitList.pop(-1)
                flag=True
                for i in range(0,len(sSplitList)):
                    if len(sSplitList[i])>=len(word):
                        if word==sSplitList[i][len(sSplitList[i])-len(word):]:
                            flag=False
                            break
                    else:
                        if sSplitList[i]==word[len(word)-len(sSplitList[i]):]:
                            s=''
                            for j in range(0,len(sSplitList)):
                                if j == i:
                                    s+=word+'#'
                                else:
                                    s+=sSplitList[j]+'#'
                            flag=False
                            break
                if flag:
                    s+=word+'#'
            print(s)
        res=len(s)
        return res
def main():
    print("hello world")

if __name__=="__main__":
    main()

