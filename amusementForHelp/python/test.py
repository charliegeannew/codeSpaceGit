##########################################################################
# File Name: test.py
# Creat Time: 2021年07月21日 星期三 11时26分22秒
# Author :Charliegean
# Mail :wht905@gmail.com
##########################################################################
#!/usr/bin/env python3
# coding=utf-8
import dsWht as ds 

def main():
    print("hello world")
    coord=ds.coordWht([0,1,2])
    coord.printCoord()
    print(coord.x)


if __name__=="__main__":
    main()

