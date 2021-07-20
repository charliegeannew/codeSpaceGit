/*************************************************************************
* File Name: 26.cpp
* Creat Time: 2021年04月20日 星期二 16时08分40秒
* Author :Charliegean
* Mail :wht905@gmail.com
*************************************************************************/
#include <iostream>
#include <vector>

using namespace std;

int removeDumplicates(vector<int>&nums);
int main()
{
    //vector<int> nums={0,0,1,1,1,2,2,3,3,4};
    vector<int> nums={1};
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<' ';
    }
    cout<<endl;
    int res=removeDumplicates(nums);
    cout<<"result is "<<res<<endl;
    for(int i=0;i<res;i++){
        cout<<nums[i]<<' ';
    }
    cout<<endl;
    return 0;
}
int removeDumplicates(vector<int>&nums){
    int len=nums.size(),res=1;
    if(len<=1){
        return len;
    }
    for(int i=1;i<len;i++){
        if(nums[i]!=nums[i-1]){
            nums[res++]=nums[i];
        }
    }
    return res;
}
