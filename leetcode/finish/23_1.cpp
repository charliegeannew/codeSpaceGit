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
ListNode * mergeTwoLists(ListNode*l1,ListNode*l2);
ListNode * mergeKLists(vector<ListNode*>&lists);
int main()
{
    ListNode *copyHead,*head,*node1,*node2,*node3,*node4,*copyHead2;
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
    copyHead=listCopy(head,2);
    copyHead2=listCopy(head,3);
    vector<ListNode*>lists;//={head,copyHead,copyHead2};
    printListNode(copyHead);
    printListNode(copyHead2);
    cout<<"n is "<<n<<endl;
    cout<<"result is "<<endl;
    ListNode * newHead=mergeKLists(lists);
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
ListNode * mergeKLists(vector<ListNode*>&lists){
    ListNode* res;
    cout<<"lists.size === "<<lists.size()<<endl;
    if(lists.size()==0){
        cout<<"=================================="<<endl;
        res=NULL;
        return res;
    }
    else{
        res=lists[0];
        for(int i=1;i<lists.size();i++){
            res=mergeTwoLists(lists[i],res);
        }
    }
    return res;
}
ListNode * mergeTwoLists(ListNode*l1,ListNode*l2){
    ListNode *res,*pt1=l1,*pt2=l2,*pt3;
    if(l1==NULL){
        res=l2;
        return res;
    }
    if(l2==NULL){
        res=l1;
        return res;
    }
    if(pt1->val<pt2->val){
        res=l1;
        pt1=pt1->next;
    }
    else{
        res=l2;
        pt2=pt2->next;
    }
    pt3=res;
    while(pt1!=NULL&&pt2!=NULL){
        if(pt1->val<pt2->val){
            pt3->next=pt1;
            pt1=pt1->next;
            pt3=pt3->next;
        }
        else{
            pt3->next=pt2;
            pt2=pt2->next;
            pt3=pt3->next;
        }
    }
    while(pt1!=NULL){
        pt3->next=pt1;
        pt1=pt1->next;
        pt3=pt3->next;
    }
    while(pt2!=NULL){
        pt3->next=pt2;
        pt2=pt2->next;
        pt3=pt3->next;
    }
    return res;
}
