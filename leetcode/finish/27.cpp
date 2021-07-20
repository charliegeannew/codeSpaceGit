/*************************************************************************
* File Name: 26.cpp
* Creat Time: 2021年04月20日 星期二 16时08分40秒
* Author :Charliegean
* Mail :wht905@gmail.com
*************************************************************************/
#include <iostream>
#include <vector>

using namespace std;

int removeDumplicates(vector<int>&nums,int val);
int main()
{
    /* vector<int> nums={0,0,1,1,1,2,2,3,3,4}; */
    //vector<int> nums={3,2,2,3};
    vector<int> nums={2};
    int val=3;
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<' ';
    }
    cout<<endl;
    int res=removeDumplicates(nums,val);
    cout<<"result is "<<res<<endl;
    for(int i=0;i<res;i++){
        cout<<nums[i]<<' ';
    }
    cout<<endl;
    return 0;
}
int removeDumplicates(vector<int>&nums,int val){
    int len=nums.size(),res=0;
    if(len<=0){
        return res;
    }
    len--;
    cout<<"len is "<<len<<endl;
    for(int i=0;i<nums.size()&&i<=len;i++){
        cout<<"nums["<<i<<"]==== "<<nums[i]<<endl;
        if(nums[i]==val){
            nums[i]=nums[len--];
            i--;
            //res++;
        }
        else{
            res++;
        }
    }
    return res;
}
