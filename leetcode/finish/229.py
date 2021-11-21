class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        dic={}
        for x in nums:
            if x in dic:
                dic[x]+=1
            else:
                dic[x]=1
        nu=int(len(nums)/3)
        res=[]
        for x in dic:
            if dic[x]>nu:
                res.append(x)
        return res
