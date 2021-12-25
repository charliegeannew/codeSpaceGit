class Solution:
    def checkOnesSegment(self, s: str) -> bool:
        res=True
        oflag=False
        for i in range(1,len(s)):
            if s[i]=='0':
                oflag=True
            elif s[i]=='1':
                if oflag:
                    res=False
                    break
                else:
                    res=True
        return res
