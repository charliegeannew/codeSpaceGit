/*************************************************************************
* File Name: 15.cpp
* Creat Time: 2021年04月17日 星期六 20时06分45秒
* Author :Charliegean
* Mail :wht905@gmail.com
*************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums);
int main()
{
    //vector<int> nums={-1,0,1,2,-1,-4};
    vector<int> nums={0,4,-1,0,3,1,1,0,-3,2,-5,-4,-3,0,0,-3};
    cout<<"num is "<<endl;
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<' ';
    }
    cout<<endl<<"result ==== "<<endl;
    vector<vector<int>> res=threeSum(nums);
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++){
            cout<<res[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}
vector<vector<int>> threeSum(vector<int>& nums){
    int len=nums.size();
    cout<<"**********************************"<<endl;
    for(int i=0;i<len;i++){
        cout<<nums[i]<<' ';
    }
    cout<<endl;
    sort(nums.begin(),nums.end());
    for(int i=0;i<len;i++){
        cout<<nums[i]<<' ';
    }
    cout<<endl;
    cout<<"**********************************"<<endl;
    vector<vector<int>> res;
    if(len>=3){
        for(int i=0;i<len;i++){
            int kb=i+1,ke=len-1;
            while(kb<ke){
                int temp=nums[kb]+nums[ke]+nums[i];
                if(temp==0){
                    if(nums[i]==0&&nums[kb]==0&&nums[ke]==0){
                        i=ke-2;
                        kb=kb-1;
                    }
                    while(ke>kb &&nums[ke-1]==nums[ke]){
                        ke--;
                    }
                    while(ke>kb && nums[kb+1]==nums[kb]){
                        kb++;
                    }
                    while(i<kb && nums[i+1]==nums[i]){
                        i++;
                    }
                    vector<int> index={nums[i],nums[kb],nums[ke]};
                    res.push_back(index);
                    ke--;
                }
                else if(temp<0){
                    kb++;
                }
                else{
                    ke--;
                }

            }
        }        
    }
    return res;
}
