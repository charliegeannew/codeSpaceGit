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
ListNode * reverseKGroup(ListNode*head,int k);
int main()
{
    ListNode *copyHead=NULL,*head,*node1,*node2,*node3,*node4,*node5,*copyHead2;
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
    node5=(ListNode*)malloc(sizeof(ListNode));
    node5->val=6;
    node4->next=node5;
    printListNode(head);
    int k=7;
    ListNode * newHead=reverseKGroup(head,k);
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
    int len=0;
    cout<<"the list is "<<endl;
    while(pt!=NULL){
        if(len++>10){
            break;
        }
        cout<<pt->val<<' ';
        pt=pt->next;
    }
    cout<<endl;
}
ListNode * reverseKGroup(ListNode*head,int k){
    ListNode *pts,*ptsk;
    if(k<=1){
        return head;
    }
    pts=head;
    ptsk=head;
    int index=1;
    //int len=0;
    while(1){
        /* len++; */
        /* if(len>50){ */
        /*     break; */
        /* } */
        if(ptsk==NULL||pts==NULL){
            break;
        }
        else{
            /* cout<<"index === "<<index<<endl; */
            if(index<k){
                index++;
                ptsk=ptsk->next;
            }
            else{
                int temp=pts->val;
                pts->val=ptsk->val;
                ptsk->val=temp;
                if(k>3){
                    //pts=pts->next;
                    int flag=0;
                    ListNode *nextPts=pts->next;
                    ListNode *beforePtsk=ptsk;
                    while(nextPts!=NULL && pts!=NULL&&nextPts!=ptsk){
                        if(flag>=k){
                            break;
                        }
                        flag++;
                        /* cout<<"flag is "<<flag<<endl; */
                        /* cout<<"11111111111next is "<<nextPts->val<<endl; */
                        /* cout<<"11111111111pts is "<<pts->val<<endl; */
                        /* cout<<"11111111111beforePtsk is "<<beforePtsk->val<<endl; */
                        nextPts=pts->next;
                        pts->next=nextPts->next;
                        //pts->next->next=nextPts;
                        nextPts->next=beforePtsk;
                        beforePtsk=nextPts;
                        //nextPts=pts->next;
                        if(pts->next==ptsk){
                            pts->next=beforePtsk;
                            break;
                        }
                    }
                }
                ptsk=ptsk->next;
                //cout<<"ptsk is "<<ptsk->val<<endl;
                pts=ptsk;
                index=1;
            }
        }
    }
    return head;
}
