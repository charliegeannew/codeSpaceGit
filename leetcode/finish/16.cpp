/*************************************************************************
* File Name: 16.cpp
* Creat Time: 2021年04月17日 星期六 22时39分02秒
* Author :Charliegean
* Mail :wht905@gmail.com
*************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int threeSumClosest(vector<int>&nums,int target);
int main()
{
    vector<int> nums={1,1,1,0};
    int target =100;
    cout<<"*************************************"<<endl;
    cout<<"nums is "<<endl;
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<' ';
    }
    cout<<endl;
    cout<<"target is "<<target<<endl;
    cout<<"res is "<<endl<<threeSumClosest(nums,target)<<endl;
    cout<<"*************************************"<<endl;
    return 0;
}
int threeSumClosest(vector<int>&nums,int target){
    int res=0;
    int diff=0;
    int len=nums.size();
    sort(nums.begin(),nums.end());
    res=nums[0]+nums[1]+nums[2];
    diff=abs(target-res);
    for(int i=0;i<len;i++){
        int kb=i+1,ke=len-1;
        while(kb<ke){
            int temp=nums[i]+nums[kb]+nums[ke];
            cout<<"temp is "<<temp<<"----target is "<<target<<endl;
            cout<<"diff is "<<diff<<"----res    is "<<res<<endl;
            if(temp>target){
                if(diff>temp-target){
                    diff=temp-target;
                    res=temp;
                }
                ke--;
            }
            else if(temp<target){
                if(diff>target-temp){
                    diff=target-temp;
                    res=temp;
                }
                kb++;
            }
            else{
                diff=0;
                res=target;
                break;
            }
        }
    }
    return res;
}
