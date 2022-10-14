/*************************************************************************
* File Name: 817.cpp
* Creat Time: 2022年10月12日 星期三 16时50分38秒
* Author :Charliegean
* Mail :wht905@gmail.com
*************************************************************************/
#include <iostream>

using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        ListNode*pt=head;
        int res=0;
        map<int,int>dic;
        for(int i=0 ;i<nums.size();i++){
            dic.insert(pair<int,int>(nums[i],i));
        }
        while(pt!=NULL){
            if(dic.find(pt->val)==dic.end()){
                pt=pt->next;
            }
            else{
                res++;
                ListNode *ptN=pt->next;
                while(ptN!=NULL){
                    if(dic.find(ptN->val)==dic.end()){
                        break;
                    }
                    else{
                        ptN=ptN->next;
                    }
                }
                pt=ptN;
            }

        }
        return res;
    }
};

int main(int argc,char ** argv)
{
    cout << "Hello world" << endl;
    return 0;
}

