/*************************************************************************
* File Name: 530.cpp
* Creat Time: 2022年10月12日 星期三 15时59分08秒
* Author :Charliegean
* Mail :wht905@gmail.com
*************************************************************************/
#include <iostream>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        int res=-1;
        if(root!=NULL){
            int lef=-1,rif=-1;
            int leM=-1,riM=-1;
            if(root->left!=NULL){
                lef=getMinimumDifference(root->left);
                TreeNode*pt=root->left;
                leM=pt->val;
                while(pt!=NULL){
                    leM=pt->val;
                    pt=pt->right;
                }
                res=abs(root->val-leM);
                if(lef>=0){
                    res=res>lef?lef:res;
                }
            }
            if(root->right!=NULL){
                rif=getMinimumDifference(root->right);
                TreeNode *pt=root->right;
                while(pt!=NULL){
                    riM=pt->val;
                    pt=pt->left;
                }
                if(res==-1){
                    res=abs(root->val-riM);
                }
                else{
                    res=res>abs(root->val-riM)?abs(root->val-riM):res;
                }
                if(rif>=0){
                    res=res>rif?rif:res;
                }
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

