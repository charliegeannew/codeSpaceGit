##########################################################################
# File Name: readwht.py
# Creat Time: 2021年04月09日 星期五 23时33分00秒
# Author :Charliegean
# Mail :wht905@gmail.com
##########################################################################
#!/usr/bin/env python3
# coding=utf-8

def main():
    i=0
    lineNum=[]
    res=[]
    with open("./res.txt",'r') as rfpt:
        for line in rfpt:
            lineList=line.split()
            res.append(lineList)
            i+=1
            #print(lineList)
            if i<-600:
                break
            if "error!!!!!!!!!!!!!!!" in lineList:
                #print(lineList)
                lineNum.append(i-1)
    rfpt.close()
    #print(lineNum)
    for i in lineNum:
        print(res[i+1])
    
if __name__=="__main__":
    main()

