class TopVotedCandidate:

    def __init__(self, persons: List[int], times: List[int]):
        self.cand=[]
        self.times=times.copy()
        pers=[]
        vote=[]
        for i in range(len(persons)):
            j=-1
            for k in range(len(pers)):
                if pers[k]==persons[i]:
                    j=k
                    break
            
            if j>-1:
                p=pers.pop(j)
                n=vote.pop(j)+1
            else:
                p=persons[i]
                n=1
            #print(j,p,n)
            r=0
            for k in range(len(pers)):
                if vote[k]<=n:
                    break
                else:
                    r+=1
            #print(r)
            pers.insert(r,p)
            vote.insert(r,n)
            self.cand.append(pers[0])
            #print(self.cand,pers,vote)

    def q(self, t: int) -> int:
        res=-1
        if t>=self.times[-1]:
            res=self.cand[-1]
        else:
            bef=0 
            end=len(self.times)
            while True:
                if bef>=end-1:
                    res=self.cand[bef]
                    break
                
                mid =int((bef+end)/2)
                #print(bef,mid,end)
                if t>self.times[mid]:
                    bef=mid
                elif t==self.times[mid]:
                    bef=mid
                    end=mid
                else:
                    end=mid
        return res


# Your TopVotedCandidate object will be instantiated and called as such:
# obj = TopVotedCandidate(persons, times)
# param_1 = obj.q(t)