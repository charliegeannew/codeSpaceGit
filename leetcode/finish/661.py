##########################################################################
# File Name: 661.py
# Creat Time: 2022年03月24日 星期四 20时32分05秒
# Author :Charliegean
# Mail :wht905@gmail.com
##########################################################################
#!/usr/bin/env python3
# coding=utf-8

def main():
    print("hello world")

if __name__=="__main__":
    main()
class Solution:
    def imageSmoother(self, img: List[List[int]]) -> List[List[int]]:
        res=[]
        m=len(img)
        n=len(img[0])
        for i in range(0,m):
            tempLine=[]
            for j in range(0,n):
                temp=img[i][j]
                num=1
                if i-1>=0:
                    temp+=img[i-1][j]
                    num+=1
                    if i+1<m:
                        temp+=img[i+1][j]
                        num+=1
                        if j-1>=0:
                            temp+=img[i-1][j-1]
                            num+=1
                            temp+=img[i][j-1]
                            num+=1
                            temp+=img[i+1][j-1]
                            num+=1
                            if j+1<n:
                                temp+=img[i-1][j+1]
                                num+=1
                                temp+=img[i][j+1]
                                num+=1
                                temp+=img[i+1][j+1]
                                num+=1
                        else:
                            if j+1<n:
                                temp+=img[i-1][j+1]
                                num+=1
                                temp+=img[i][j+1]
                                num+=1
                                temp+=img[i+1][j+1]
                                num+=1
                    else:
                        if j-1>=0:
                            temp+=img[i-1][j-1]
                            num+=1
                            temp+=img[i][j-1]
                            num+=1
                            if j+1<n:
                                temp+=img[i-1][j+1]
                                num+=1
                                temp+=img[i][j+1]
                                num+=1
                        else:
                            if j+1<n:
                                temp+=img[i-1][j+1]
                                num+=1
                                temp+=img[i][j+1]
                                num+=1
                else:
                    if i+1<m:
                        temp+=img[i+1][j]
                        num+=1
                        if j-1>=0:
                            temp+=img[i][j-1]
                            num+=1
                            temp+=img[i+1][j-1]
                            num+=1
                            if j+1<n:
                                temp+=img[i][j+1]
                                num+=1
                                temp+=img[i+1][j+1]
                                num+=1
                        else:
                            if j+1<n:
                                temp+=img[i][j+1]
                                num+=1
                                temp+=img[i+1][j+1]
                                num+=1
                    else:
                        if j-1>=0:
                            temp+=img[i][j-1]
                            num+=1
                            if j+1<n:
                                temp+=img[i][j+1]
                                num+=1
                        else:
                            if j+1<n:
                                temp+=img[i][j+1]
                                num+=1
                temp=floor(temp/num)   
                tempLine.append(temp)
            res.append(tempLine)
        return res
