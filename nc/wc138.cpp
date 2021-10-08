/*************************************************************************
* File Name: wc138.cpp
* Creat Time: 2021年09月29日 星期三 11时24分38秒
* Author :Charliegean
* Mail :wht905@gmail.com
*************************************************************************/
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
vector<vector<int>> threeOrders(TreeNode* root);
void printTreeBef(TreeNode* root);
void printTreeMid(TreeNode* root);
void printTreeNex(TreeNode* root);
int main(int argc,char ** argv)
{
    cout << "Hello world" << endl;
    TreeNode * root = new TreeNode();
    TreeNode * left = new TreeNode();
    TreeNode * right = new TreeNode();
    root->val=1;
    left->val=2;
    right->val=3;

    root->left=left;
    root->right=right;

    cout<<"bef print  "<<endl;
    printTreeBef(root);
    cout<<endl;
    cout<<"mid print  "<<endl;
    printTreeMid(root);
    cout<<endl;
    cout<<"Nex print  "<<endl;
    printTreeNex(root);
    cout<<endl;
    vector<vector<int>>res=threeOrders(root);
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++){
            cout<<res[i][j]<<'\t';
        }
        cout<<endl;
    }
    return 0;
}
void printTreeBef(TreeNode* root){
    if(root!=NULL){
        cout<<root->val<<'\t';
        printTreeBef(root->left);
        /* cout<<root->val<<'\t'; */
        printTreeBef(root->right);
    }
}
void printTreeMid(TreeNode* root){
    if(root!=NULL){
        printTreeMid(root->left);
        cout<<root->val<<'\t';
        /* cout<<root->val<<'\t'; */
        printTreeMid(root->right);
    }
}
void printTreeNex(TreeNode* root){
    if(root!=NULL){
        printTreeNex(root->left);
        printTreeNex(root->right);
        cout<<root->val<<'\t';
    }
}
vector<vector<int>> threeOrders(TreeNode* root){
    vector<vector<int>>res;
    vector<int> bef;
    vector<int> mid;
    vector<int> nex;
    vector<TreeNode*> stack;
    vector<int> flagLeft;
    vector<int> flagRight;
    int stackLen=0;
    if(root!=NULL){
        stack.push_back(root);
        stackLen++;
        flagLeft.push_back(1);
        flagRight.push_back(1);
    }
    while(stackLen>0){
        cout<<"stackLen is "<<stackLen<<endl;
        for(int i=0;i<stackLen;i++){
            cout<<stack[i]->val<<'\t';
        }
        cout<<endl;
        TreeNode* top=stack[stackLen-1];
        if(top->left!=NULL){
            stack.push_back(top->left);
            stackLen++;
        }
        else if(top->right!=NULL){
            stack.push_back(top->right);
            stackLen++;
        }
        else{
            stack.pop_back();
            stackLen--;
        }
    }
    return res;
    
}
