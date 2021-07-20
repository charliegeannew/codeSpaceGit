/*************************************************************************
* File Name: 19.cpp
* Creat Time: 2021年04月19日 星期一 16时55分41秒
* Author :Charliegean
* Mail :wht905@gmail.com
*************************************************************************/
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

struct ListNode{
    int val;
    ListNode *next=NULL;
};
void printListNode(ListNode*head);
ListNode * listCopy(ListNode*head,int n);
ListNode * swapPairs(ListNode*head);
int main()
{
    ListNode *copyHead=NULL,*head,*node1,*node2,*node3,*node4,*copyHead2;
    head=(ListNode*)malloc(sizeof(ListNode));
    head->val=1;
    /* node1=(ListNode*)malloc(sizeof(ListNode)); */
    /* node1->val=2; */
    /* head->next=node1; */
    /* node2=(ListNode*)malloc(sizeof(ListNode)); */
    /* node2->val=3; */
    /* node1->next=node2; */
    /* node3=(ListNode*)malloc(sizeof(ListNode)); */
    /* node3->val=4; */
    /* node2->next=node3; */
    /* node4=(ListNode*)malloc(sizeof(ListNode)); */
    /* node4->val=5; */
    /* node3->next=node4; */
    /* printListNode(head); */
    head->next=NULL;
    ListNode * newHead=swapPairs(head);
    printListNode(newHead);
    return 0;
}
ListNode * listCopy(ListNode*head,int n){
    ListNode *pt=head,*pt2;
    ListNode *copyHead;
    copyHead=(ListNode*)malloc(sizeof(ListNode));
    copyHead->val=head->val*n;
    pt=pt->next;
    pt2=copyHead;
    while(pt!=NULL){
        ListNode *nextNode;
        nextNode=(ListNode*)malloc(sizeof(ListNode));
        nextNode->val=pt->val*n;
        pt2->next=nextNode;
        pt=pt->next;
        pt2=pt2->next;
    }
    return copyHead;
}
void printListNode(ListNode*head){
    ListNode *pt;
    pt=head;
    cout<<"the list is "<<endl;
    while(pt!=NULL){
        cout<<pt->val<<' ';
        pt=pt->next;
    }
    cout<<endl;
}
ListNode * swapPairs(ListNode*head){
    ListNode *pts;
    pts=head;
    while(pts!=NULL &&pts->next!=NULL){
        int temp=pts->val;
        pts->val=pts->next->val;
        pts->next->val=temp;
        pts=pts->next->next;
    }
    return head;
}
