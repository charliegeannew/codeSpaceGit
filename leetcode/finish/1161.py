##########################################################################
# File Name: 1161.py
# Creat Time: 2021年10月18日 星期一 17时33分31秒
# Author :Charliegean
# Mail :wht905@gmail.com
##########################################################################
#!/usr/bin/env python3
# coding=utf-8

class Solution:
    def maxLevelSum(self, root: TreeNode) -> int:
        res=[]
        listNum=1
        if(root==None):
            listNum=1
        else:
            que=[]
            hang=[]
            que.append(root)
            hang.append(1)
            while len(que)>0:
                tempNode=que[0]
                tempHang=hang[0]
                if(tempHang>len(res)):
                    res.append(tempNode.val)
                else:
                    res[tempHang-1]+=tempNode.val
                que.pop(0)
                hang.pop(0)
                if(tempNode.left!=None):
                    que.append(tempNode.left)
                    hang.append(tempHang+1)
                if(tempNode.right!=None):
                    que.append(tempNode.right)
                    hang.append(tempHang+1)
            #maxNum=max(res)
            #for i in range(0,len(res)):
             #   if(res[i]==maxNum):
              #      listNum=i+1
               #     break
            listNum=1
            for i in range(1,len(res)):
                if(res[listNum-1]<res[i]):
                    listNum=i+1
            #print(listNum)
        return listNum
def main():
    print("hello world")

if __name__=="__main__":
    main()

