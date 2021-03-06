#!/usr/bin/env python
# coding=utf-8
class Solution:
    def getValidT9Words(self, num: str, words: List[str]) -> List[str]:
        dic={"a":"2","b":"2","c":"2",
            "d":"3","e":"3","f":"3",
            "g":"4","h":"4","i":"4",
            "j":"5","k":"5","l":"5",
            "m":"6","n":"6","o":"6",
            "p":"7","q":"7","r":"7","s":"7",
            "t":"8","u":"8","v":"8",
            "w":"9","x":"9","y":"9","z":"9"
        }
        print(dic)
        res=[]
        for word in words:
            flag=True
            for i in range(0,len(word)):
                if(dic[word[i]]!=num[i]):
                    flag=False
                    break
            if flag:
                res.append(word)
        return res
