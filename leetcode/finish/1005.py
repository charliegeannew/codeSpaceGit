class Solution:
    def largestSumAfterKNegations(self, nums: List[int], k: int) -> int:
        nums.sort()
        ind=0
        sm=-1
        for i in range(len(nums)):
            if nums[i]<0:
                if k>0:
                    nums[i]*=-1
                    if sm==-1 or sm>nums[i]:
                        sm=nums[i]
                        ind=i 
                    k-=1
                else:
                    break
            else:
                if sm == -1 or sm>nums[i]:
                    sm=nums[i]
                    ind=i
                break
        if k%2==1:
            nums[ind]*=-1
        return sum(nums)