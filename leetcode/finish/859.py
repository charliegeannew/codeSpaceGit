class Solution:
    def buddyStrings(self, s: str, goal: str) -> bool:
        res=False
        if len(s)==len(goal):
            fir=-1
            sec=-1
            dic={}
            flag=False
            for i in range(len(s)):
                if s[i] in dic:
                    flag=True
                else:
                    dic[s[i]]=1
                if s[i]!=goal[i]:
                    if fir==-1:
                        fir=i
                    elif sec==-1:
                        sec=i
                    else:
                        fir=-2
                        sec=-2
            if fir==-1:
                res=flag
            elif fir>=0:
                if sec!=-1:
                    if s[fir]==goal[sec] and s[sec]==goal[fir]:
                        res=True
        return res
