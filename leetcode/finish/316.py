class Solution:
    def removeDuplicateLetters(self, s: str) -> str:
        #begDic={'a':-1,'b':-1,'c':-1,'d':-1,'e':-1,'f':-1,'g':-1,'h':-1,'i':-1,'j':-1,'k':-1,'l':-1,'m':-1,'n':-1,'o':-1,'p':-1,'q':-1,'r':-1,'s':-1,'t':-1,'u':-1,'v':-1,'w':-1,'x':-1,'y':-1,'z':-1}
        dic={'a':-1,'b':-1,'c':-1,'d':-1,'e':-1,'f':-1,'g':-1,'h':-1,'i':-1,'j':-1,'k':-1,'l':-1,'m':-1,'n':-1,'o':-1,'p':-1,'q':-1,'r':-1,'s':-1,'t':-1,'u':-1,'v':-1,'w':-1,'x':-1,'y':-1,'z':-1}
        res=''
        for c in s:
            dic[c]=1
        chDic={}
        chstr=''
        for key in dic:
            if dic[key]!=-1:
                chDic[key]=[]
                chstr+=key
        for i in range(len(s)):
            chDic[s[i]].append(i)
        i=0
        index=0
        #print(chDic)
        while  len(chstr)!=0:
            flag=True
            j=0
            #print(i,chDic[chstr[i]],chstr,chstr[i],index,res)
            while  chDic[chstr[i]][j]<index :
                j+=1
                if j ==len(chDic[chstr[i]]):
                    break
            if j>=len(chDic[chstr[i]]):
                flag=False
            else:
                for k in range(len(chstr)):
                    if chDic[chstr[k]][-1]<chDic[chstr[i]][j]:
                        flag=False
                        break
            if flag:
                res+=chstr[i]
                index=chDic[chstr[i]][j]
                chDic.pop(chstr[i])
                chstr=chstr[:i]+chstr[i+1:]
                i=0
            else:
                i+=1
        return res 