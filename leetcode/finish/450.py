##########################################################################
# File Name: 450.py
# Author: Charliegean
# mail: wht905@gmail.com
# Created Time: Mon 27 Dec 2021 04:55:57 PM CST
#########################################################################
#!/usr/bin/env python3
# coding=utf-8

def main():
    print("hello world")

if __name__=="__main__":
    main()
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def deleteNode(self, root: Optional[TreeNode], key: int) -> Optional[TreeNode]:
        res=root
        if root==None:
            res=None
        elif root.val==key:
            if root.left==None:
                if root.right==None:
                    res=None
                else:
                    res=root.right
            elif root.right==None:
                res=root.left
            else:
                res=root.right
                pt=root.right
                while True:
                    if pt.left==None:
                        break
                    else:
                        pt=pt.left
                pt.left=root.left
        else:
            res=root
            pt=root
            flag=False
            ptp=root
            ind=-1
            while True:
                if pt==None:
                    break
                if pt.val==key:
                    flag=True 
                    break
                elif pt.val>key:
                    ptp=pt 
                    ind=0
                    pt=pt.left
                else:
                    ptp=pt
                    ind=1
                    pt=pt.right
            if flag:
                if pt.left==None:
                    if ind==0:
                        ptp.left=pt.right
                    else:
                        ptp.right=pt.right
                elif pt.right==None:
                    if ind==0:
                        ptp.left=pt.left 
                    else:
                        ptp.right=pt.left
                else:
                    if ind==0:
                        ptp.left=pt.right
                    else:
                        ptp.right=pt.right
                    ptn=pt.right
                    while True:
                        if ptn.left==None:
                            break
                        else:
                            ptn=ptn.left
                    ptn.left=pt.left
        return res 

