##########################################################################
# File Name: 736.py
# Creat Time: 2021年10月18日 星期一 15时42分05秒
# Author :Charliegean
# Mail :wht905@gmail.com
##########################################################################
#!/usr/bin/env python3
# coding=utf-8

class Solution:
    def evaluate(self, expression: str) -> int:
        tempExpression=expression
        for i in range(len(expression)-1,-1,-1):
            if(tempExpression[i]=='('):
                tempExpression=tempExpression[:i+1]+' '+tempExpression[i+1:]
            elif tempExpression[i]==')':
                tempExpression=tempExpression[:i]+' '+tempExpression[i:]
        print(tempExpression)
        print(tempExpression.split(' '))
        listExp=tempExpression.split(' ')
        listExp.pop(0)
        listExp.pop(-1)
        print(listExp)
        res=0
        sigDic={}
        sonExpre=''
        leftNum=0
        rightNum=0
        allNum=0
        if(listExp[0]=='let'):
            pass
        elif listExp[0]=='mult':
            pass
        elif listExp[0]=='add':
            i=1
            leftNum=0
            rightNum=0
            for x in listExp:
                if x == '(':
                    leftNum+=1
                elif x == ')':
                    rightNum+=1
                elif x=='':
                    pass
                elif x[0]-'0'>=0 and x[0]-'0'<=9:
                    sigDic={}
        else:
            print("error")
            pass
        numDic={}
        return res 

def main():
    print("hello world")
    inp="(let x 2 (mult x (let x 3 y 4 (add x y))))"
    print(inp)
    res=0
    sol=Solution()
    res=sol.evaluate(inp)
    print(res)

if __name__=="__main__":
    main()

