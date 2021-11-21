##########################################################################
# File Name: 929.py
# Author: Charliegean
# mail: wht905@gmail.com
# Created Time: Sun 07 Nov 2021 05:45:44 PM CST
#########################################################################
#!/usr/bin/env python3
# coding=utf-8
class Solution:
    def numUniqueEmails(self, emails: List[str]) -> int:
        res=0
        dic={}
        for x in emails:
            x=x.split('@')
            name=x[0]
            name=name.split('+')
            name=name[0]
            name=self.deletePoint(name)
            name=name+'@'+x[1]
            if name in dic:
                continue
            else:
                dic[name]=1
                res+=1
        return res
    def deletePoint(self,name:str)-> str:
        res=''
        for i in range(len(name)):
            if name[i]!='.':
                res+=name[i]
        return res
def main():
    print("hello world")

if __name__=="__main__":
    main()

