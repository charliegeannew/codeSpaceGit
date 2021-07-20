/*************************************************************************
* File Name: 18.cpp
* Creat Time: 2021年04月19日 星期一 16时06分06秒
* Author :Charliegean
* Mail :wht905@gmail.com
*************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>>fourSum(vector<int>&nums,int target);
int main()
{
    vector<int>nums={1,0,-1,0,-2,2,0,0,0,0,0};
    int target=0;
    cout<<"target is "<<target<<endl<<"numms is "<<endl;
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<' ';
    }
    cout<<endl;
    vector<vector<int>>res=fourSum(nums,target);
    cout<<"res is "<<endl;
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++){
            cout<<res[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}
vector<vector<int>>fourSum(vector<int>&nums,int target){
    sort(nums.begin(),nums.end());
    vector<vector<int>>res;
    if(nums.size()<=3){
        return res;
    }
    for(int i=0;i<nums.size();i++){
        for(int j=i+1;j<nums.size();j++){
            int kb=j+1,ke=nums.size()-1;
            while(kb<ke){
                int temp=nums[i]+nums[j]+nums[kb]+nums[ke];
                if(temp==target){
                    while(kb<ke&&kb+1<ke){
                        if(nums[kb]==nums[kb+1]){
                            kb++;
                        }
                        else{
                            break;
                        }
                    }
                    while(j<kb&&j+1<kb){
                        if(nums[j]==nums[j+1]){
                            j++;
                        }
                        else{
                            break;
                        }
                    }
                    while(i<j&&i+1<j){
                        if(nums[i]==nums[i+1]){
                            i++;
                        }
                        else{
                            break;
                        }
                    }
                    vector<int> tempVec={nums[i],nums[j],nums[kb],nums[ke]};
                    res.push_back(tempVec);
                    kb++;
                }
                else if(temp<target){
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
