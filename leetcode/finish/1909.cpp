/*************************************************************************
*File Name: 1909.cpp
*Author: Charliegean
*wht905@gmail.com
*Created Time: Wed Oct 19 21:51:29 2022
 ************************************************************************/
#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world" << endl;
    return 0;
}

class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        bool res=true;
        int bef=nums[0];
        int ind=-1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<=nums[i-1]){
                if(ind==-1){
                    ind=i;
                }
                else{
                    res=false;
                    break;
                }
            }
        }
        if(ind==-1){
            res=true;
        }
        else if(res){
            if(ind==1){
                res=true;
            }
            else if(ind==nums.size()-1){
                res=true;
            }
            else{
                if(nums[ind-2]<nums[ind]||nums[ind-1]<nums[ind+1]){
                    res=true;
                }
                else{
                    res=false;
                }
            }
        }
        return res;
    }
};
