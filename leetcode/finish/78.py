iclass Solution:
    numsList=[]
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res=[]
        self.numsList=nums
        res=self.dft(0,len(nums),nums)
        return res 
    
    def dft(self,now:int,n:int,subNums:List[int]) -> List[List[int]]:
        res=[]
        if(now<n):
            #print(subNums)
            #print(subNums.remove(subNums[0]))
            temp=[]
            for x in subNums:
                if x!=self.numsList[now]:
                    temp.append(x)
            res+=self.dft(now+1,n,subNums)
            #res+=self.dft(now+1,n,subNums.remove(self.numsList[now]))
            res+=self.dft(now+1,n,temp)
        elif(now == n):
            res.append(subNums)
        else:
            res.append([])
            print("error ")
        return res  
