#!/usr/bin/env python
# coding=utf-8
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        pt=head
        while pt!=None:
            ptN = pt.next
            while ptN != None:
                if ptN.val == pt.val:
                    ptN=ptN.next
                else:
                    break
            pt.next=ptN
            pt=ptN
        return head 
