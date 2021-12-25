class Solution:
    def superPow(self, a: int, b: List[int]) -> int:
        if a>1337:
            a=a%1337
        if a==1:
            return 1
        elif len(b)==1:
            return pow(a,b[0])%1337
        else:
            res=1
            flag=[0 for i in range(len(b))]
            flag[0]=a
            flag[1]=pow(a,10)%1337
            
            for i in range(2,len(b)):
                flag[i]=(flag[i-1]**10)%1337
            j=0
            for i in range(len(b)-1,-1,-1):
                if b[i]!=0:
                    res=(res*((flag[j]**b[i])%1337))%1337
                j+=1
        return res 