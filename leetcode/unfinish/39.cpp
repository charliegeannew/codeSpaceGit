/*************************************************************************
* File Name: 39.cpp
* Creat Time: 2021年07月28日 星期三 00时52分36秒
* Author :Charliegean
* Mail :wht905@gmail.com
*************************************************************************/
#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    vector<vector<int>>combinationSum(vector<int>&candidates,int target);
    void cycleArr(int index,int target);
    void setArr(int index,int target);
    vector<vector<int>>arr;
    vector<int>candidates;
    
};
int main(int argc,char ** argv)
{
    cout << "Hello world" << endl;
    vector<int>tVec={2,3,6,7};
    int target=7;
    cout<<"tVec is "<<endl;
    for(int i=0;i<tVec.size();i++){
        cout<<tVec[i]<<' ';
    }
    cout<<endl;
    cout<<"target is "<<endl<<target<<endl;
    vector<vector<int>>res;
    Solution sol;
    res=sol.combinationSum(tVec,target);
    cout<<"res is"<<endl;
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++){
            cout<<res[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}
vector<vector<int>> Solution::combinationSum(vector<int>&candidates,int target){
    vector<vector<int>> res;
    return res;
}
void Solution::cycleArr(int index,int target){
    if(index<0|target<=0){
        cout<<"endl"<<endl;
    }
    else{

    }
}
void Solution::setArr(int index,int target){
    for(int i=0;i<target;i++){
        vector<int> temp;
        for(int j=0;j<index;j++){
            temp.push_back(-1);
        }
        this->arr.push_back(temp);
    }
}
