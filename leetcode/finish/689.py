class Solution:
    def maxSumOfThreeSubarrays(self, nums: List[int], k: int) -> List[int]:
        res=[0,0,0]
        resF=True
        resN=0
        numSum=[sum(nums[:k])]
        for i in range(1,len(nums)-k+1):
            numSum.append(numSum[i-1]-nums[i-1]+nums[i+k-1])
        kMaxInd=[len(numSum)-1]
        kMaxNum=[numSum[-1]]
        for i in range(len(numSum)-2,-1,-1):
            if numSum[i]>=kMaxNum[0]:
                kMaxNum.insert(0,numSum[i])
                kMaxInd.insert(0,i)
            else:
                kMaxInd.insert(0,kMaxInd[0])
                kMaxNum.insert(0,kMaxNum[0])
        jMaxInd=[[len(numSum)-k-1,len(numSum)-1]]
        jMaxNum=[numSum[jMaxInd[0][0]]+numSum[jMaxInd[0][1]]]
        #print(jMaxInd,jMaxNum)
        for j in range(len(numSum)-k-1,-1,-1):
            temp=numSum[j]+kMaxNum[j+k]
            if temp>=jMaxNum[0]:
                jMaxNum.insert(0,temp)
                jMaxInd.insert(0,[j,kMaxInd[j+k]])
            else:
                jMaxNum.insert(0,jMaxNum[0])
                jMaxInd.insert(0,jMaxInd[0])
        for i in range(len(numSum)-2*k):
            #print(res,resN,resF)
            if resF:
                resF=False
                resN=numSum[i]+jMaxNum[i+k]
                res=[i,jMaxInd[i+k][0],jMaxInd[i+k][1]]
            else:
                if numSum[i]+jMaxNum[i+k]>resN:
                    resN=numSum[i]+jMaxNum[i+k]
                    res=[i,jMaxInd[i+k][0],jMaxInd[i+k][1]]
        #print(numSum)
        #print(kMaxNum)
        #print(kMaxInd)
        #print(jMaxInd)
        #print(jMaxNum)
        return res