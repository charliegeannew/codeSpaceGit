class Solution:
    def getMoneyAmount(self, n: int) -> int:
        if n<5:
            flag=[0,1,2,4]
            return flag[n-1]
        else:
            flag=[[-1 for i in range(n)] for j in range(n)]
           
            for i in range(n):
                flag[i][i]=0
                if i+1<n:
                    flag[i][i+1]=i+1
                if i+2<n:
                    flag[i][i+2]=i+2
            for j in range(3,n):
                for i in range(n):
                    if i+j<n:
                        tempRes=i+int(j/2)+1+max(flag[i][i+int(j/2)-1],flag[i+int(j/2)+1][i+j])
                        for k in range(int(j/2),j):
                            temp=i+k+1+max(flag[i][i+k-1],flag[i+k+1][i+j])
                            #print(tempRes,temp,i,j,k)
                            if tempRes>temp:
                                tempRes=temp
                            #else:
                             #   flag[i][i+j]=tempRes
                              #  break
                        flag[i][i+j]=tempRes
            #for line in flag:
             #   print(line)
            return flag[0][n-1]