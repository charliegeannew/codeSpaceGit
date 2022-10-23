/*************************************************************************
*File Name: 1379.cpp
*Author: Charliegean
*wht905@gmail.com
*Created Time: Sat Oct 15 21:53:58 2022
 ************************************************************************/
#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world" << endl;
    return 0;
}
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode*res=NULL;
        if(original==NULL){
            res=NULL;
        }
        else if(original==target){
            res=cloned;
        }
        else{
            TreeNode *le=getTargetCopy(original->left,cloned->left,target);
            if(le!=NULL){
                res=le;
            }
            else{
                TreeNode *ri=getTargetCopy(original->right,cloned->right,target);
                res=ri;
            }
            
        }
        return res;
    }
};
