#!/usr/bin/env python
# coding=utf-8
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeZeroSumSublists(self, head: ListNode) -> ListNode:
        pt=head
        dic={}
        dic[0]=None
        pre=0
        res=head
        bef=head 
        #pt=pt.next
        while pt!=None:
            pre+=pt.val
            if pre in dic:
                if dic[pre]==None:
                    res=pt.next
                    dic.clear()
                    dic[0]=None
                else:
                    ptN=dic[pre].next
                    now=pre
                    while ptN!=pt:
                        now+=ptN.val
                        dic.pop(now)
                        ptN=ptN.next                        
                    dic[pre].next=pt.next
            else:
                dic[pre]=pt
            pt=pt.next
        while res!=None and res.val == 0 :
            res=res.next
        return res 

