##########################################################################
# File Name: 1160.py
# Creat Time: 2021年10月18日 星期一 17时09分16秒
# Author :Charliegean
# Mail :wht905@gmail.com
##########################################################################
#!/usr/bin/env python3
# coding=utf-8

class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        res=0
        chaDic={}
        for i in range(0,len(chars)):
            chaDic[chars[i]]=0
        for i in range(0,len(chars)):
            chaDic[chars[i]]+=1
        print(chaDic)
        for word in words:
            temp=chaDic.copy()
            print(temp)
            print(word)
            flag=True
            for x in word:
                if x in temp:
                    temp[x]-=1
                    if(temp[x]<0):
                        flag=False
                        break
                else:
                    flag=False
            if(flag):
                res+=len(word)
        return res
def main():
    print("hello world")

if __name__=="__main__":
    main()

