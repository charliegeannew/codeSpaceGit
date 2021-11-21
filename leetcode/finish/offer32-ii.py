##########################################################################
# File Name: offer32-ii.py
# Creat Time: 2021年10月17日 星期日 22时10分22秒
# Author :Charliegean
# Mail :wht905@gmail.com
##########################################################################
#!/usr/bin/env python3
# coding=utf-8

def levelOrder(self, root: TreeNode) -> List[List[int]]:
    que=[]
    hang=[]
    res=[]
    if(root==None):
        return res
    que.append(root)
    hang.append(1)
    while len(que)>0:
        tempNode=que[0]
        tempHang=hang[0]
        que.pop(0)
        hang.pop(0)
        if(tempNode.left!=None):
            que.append(tempNode.left)
            hang.append(tempHang+1)
        if(tempNode.right!=None):
            que.append(tempNode.right)
            hang.append(tempHang+1)
        if(len(res)<tempHang):
            temp=[]
            temp.append(tempNode.val)
            res.append(temp)
        else:
            res[tempHang-1].append(tempNode.val)
    return res
def main():
    print("hello world")

if __name__=="__main__":
    main()

