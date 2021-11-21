##########################################################################
# File Name: finish/559.py
# Author: Charliegean
# mail: wht905@gmail.com
# Created Time: Sun 21 Nov 2021 07:25:11 PM CST
#########################################################################
#!/usr/bin/env python3
# coding=utf-8

def main():
    print("hello world")

if __name__=="__main__":
    main()
"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    def maxDepth(self, root: 'Node') -> int:
        res=0
        if root==None:
            res=0
        else:
            #res=1
            for children in root.children:
                #print(children.val)
                res=max(res,self.maxDepth(children))
            res+=1
        return res 
