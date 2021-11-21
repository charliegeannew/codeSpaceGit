##########################################################################
# File Name: 240.py
# Author: Name
# mail: Name@qq.com
# Created Time: Mon 25 Oct 2021 09:08:16 PM CST
#########################################################################
#!/usr/bin/env python3
# coding=utf-8

class Solution:
    def searchMatrix(self, matrix, target) :
        res=False
        res=self.doufenFind(matrix,0,0,len(matrix)-1,len(matrix[0])-1,target)
        return res

    def doufenFind(self,matrix,begX,begY,endX,endY,target):
        res=False
        if begX>endX or begY>endY:
            res=False
        elif begX==endX:
            for i in range(begY,endY+1):
                if target==matrix[begX][i]:
                    res=True
                    break
        elif begY == endY:
            for i in range(begX,endX+1):
                if target==matrix[i][begY]:
                    res=True
                    break
        else:
            midX=int((begX+endX)/2)
            midY=int((begY+endY)/2)
            if matrix[midX][midY]==target or matrix[begX][begY]==target or matrix[endX][endY]==target:
                res=True
            elif matrix[midX][midY]>target:
                res=self.doufenFind(matrix,begX,begY,midX-1,midY-1,target)
                res=res or self.doufenFind(matrix,midX,begY,endX,midY,target)
                res=res or self.doufenFind(matrix,begX,midY,midX,endY,target)
            else:
                res=self.doufenFind(matrix,midX+1,midY+1,endX,endY,target)
                res=res or self.doufenFind(matrix,midX,begY,endX,midY,target)
                res=res or self.doufenFind(matrix,begX,midY,midX,endY,target)
        return res
def main():
    print("hello world")
    sol=Solution()
    matrix=[
        [1,4,5,11,15],
        [2,5,8,12,19],
        [3,6,9,16,22],
        [10,13,14,17,24],
        [18,21,23,26,30]
    ]
    target=5
    for x in matrix:
        print(x)
    print("target is ",target)
    print(sol.searchMatrix(matrix,target))

if __name__=="__main__":
    main()

