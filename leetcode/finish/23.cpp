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
    printListNode(head);
    copyHead=listCopy(head,2);
    copyHead2=listCopy(head,3);
    vector<ListNode*>lists={head,copyHead,copyHead2};
    printListNode(copyHead);
    printListNode(copyHead2);
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
    int len=lists.size();
    if(len==0){
        res=NULL;
        return res;
    }
    else{
        vector<ListNode*>pts;
        int minIndex=0;
        for(;minIndex<len;minIndex++){
            if(lists[minIndex]!=NULL){
                break;
            }
        }
        if(minIndex==len){
            return res;
        }
        ListNode*ptTemp=lists[minIndex];
        //pts.push_back(ptTemp);
        for(int i=1;i<len;i++){
       //     ptTemp=lists[i];
         //   pts.push_back(ptTemp);
            if(lists[i]!=NULL){
                if(lists[minIndex]->val>lists[i]->val){
                    minIndex=i;
                }
            }
        }
        cout<<"----min === "<<minIndex<<endl;
        res=lists[minIndex];
        ptTemp=res;
        if(lists[minIndex]!=NULL){
            lists[minIndex]=lists[minIndex]->next;
        }
        while(1){
            for(minIndex=0;minIndex<len;minIndex++){
                if(lists[minIndex]!=NULL){
                    break;
                }
            }
            if(minIndex==len){
                break;
            }
            for(int i=minIndex;i<len;i++){
                if(lists[i]!=NULL){
                    if(lists[minIndex]->val>lists[i]->val){
                        minIndex=i;
                    }
                }
            }
            cout<<"minIndex is "<<minIndex<<endl;
            ptTemp->next=lists[minIndex];
            lists[minIndex]=lists[minIndex]->next;
            ptTemp=ptTemp->next;
        }
    }
    return res;
}
