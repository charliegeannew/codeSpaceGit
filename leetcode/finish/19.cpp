/*************************************************************************
* File Name: 19.cpp
* Creat Time: 2021年04月19日 星期一 16时55分41秒
* Author :Charliegean
* Mail :wht905@gmail.com
*************************************************************************/
#include <iostream>
#include <cstdlib>

using namespace std;

struct ListNode{
    int val;
    ListNode *next=NULL;
};
ListNode *removeNthFromEnd(ListNode* head,int n);
void printListNode(ListNode*head);
int main()
{
    ListNode* head,*node1,*node2,*node3,*node4;
    head=(ListNode*)malloc(sizeof(ListNode));
    head->val=1;
    node1=(ListNode*)malloc(sizeof(ListNode));
    node1->val=2;
    head->next=node1;
    node2=(ListNode*)malloc(sizeof(ListNode));
    node2->val=3;
    node1->next=node2;
    node3=(ListNode*)malloc(sizeof(ListNode));
    node3->val=4;
    node2->next=node3;
    node4=(ListNode*)malloc(sizeof(ListNode));
    node4->val=5;
    node3->next=node4;
    int n=1;
    printListNode(head);
    cout<<"n is "<<n<<endl;
    cout<<"result is "<<endl;
    printListNode(removeNthFromEnd(head,n));
    return 0;
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
ListNode *removeNthFromEnd(ListNode* head,int n){
    int index=0;
    ListNode *pt=head;
    while(pt!=NULL){
        index++;
        pt=pt->next;
    }
    cout<<"index is "<<index <<endl;
    index-=n;
    if(index==0){
        return head->next;
    }
    pt=head;
    for(int i=0;i<index-1;i++){
        pt=pt->next;
    }
    pt->next=pt->next->next;
    printListNode(pt);
    return head;
}
