class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        res=[]
        pdic={}
        if len(s)>=len(p):
            for c in p:
                if c in pdic:
                    pdic[c]+=1
                else:
                    pdic[c]=1
            for i in range(len(p)):
                if s[i] in pdic:
                    pdic[s[i]]-=1
                else:
                    pdic[s[i]]=-1
            if self.ifEqual(pdic):
                res.append(0)
            for i in range(1,len(s)-len(p)+1):
                if s[i-1] in pdic:
                    pdic[s[i-1]]+=1
                else:
                    pdic[s[i-1]]=1
                if s[i+len(p)-1] in pdic:
                    pdic[s[i+len(p)-1]]-=1
                else:
                    pdic[s[i+len(p)-1]]=-1
                if self.ifEqual(pdic):
                    res.append(i)
        return res

    def ifEqual(self,dic:dict)->bool:
        #print(s,p)
        res=True
        for key in dic:
            if dic[key]!=0:
                res=False
                break
        flag=[]
        for key in dic:
            if dic[key] == 0:
                flag.append(key)
        for c in flag:
            dic.pop(c)
        return res 