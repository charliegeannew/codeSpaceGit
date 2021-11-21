##########################################################################
# File Name: 872.py
# Creat Time: 2021年10月17日 星期日 22时12分25秒
# Author :Charliegean
# Mail :wht905@gmail.com
##########################################################################
#!/usr/bin/env python3
# coding=utf-8

class Solution:
    leafList1=[]
    leafList2=[]
    def getLeaf(self,root:TreeNode,flag:int):
        if(root==None):
            pass
        else:
            if(root.left==None):
                if(root.right==None):
                    if(flag==1):
                        self.leafList1.append(root.val)
                    else:
                        self.leafList2.append(root.val)
                else:
                    self.getLeaf(root.right,flag)
            else:
                self.getLeaf(root.left,flag)
                self.getLeaf(root.right,flag)

    def leafSimilar(self, root1: TreeNode, root2: TreeNode) -> bool:
        res=True
        self.leafList1=[]
        self.leafList2=[]
        if(root1==None):
            if(root2==None):
                res=True
            else:
                res=False
        else:
            if(root2==None):
                res=False
            else:
                #leafList1=[]
                #leafList2=[]
                self.getLeaf(root1,1)
                self.getLeaf(root2,2)
                print(self.leafList1)
                print(self.leafList2)
                len1=len(self.leafList1)
                len2=len(self.leafList2)
                if(len1 !=len2):
                    res=False
                else:
                    for i in range(0,len1):
                        if(self.leafList2[i]!=self.leafList1[i]):
                            res=False
                            break
        return res

def main():
    print("hello world")

if __name__=="__main__":
    main()

