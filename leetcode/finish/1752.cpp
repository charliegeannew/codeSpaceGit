/*************************************************************************
*File Name: 1752.cpp
*Author: Charliegean
*wht905@gmail.com
*Created Time: Sun Oct 16 17:46:44 2022
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
    bool check(vector<int>& nums) {
        bool res=true;
        int fir=-1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[i-1]){
                if(fir==-1){
                    fir=i;
                }
                else{
                    res=false;
                    break;
                }
            }
        }
        if(fir>=0 &&res){
            for(int i=fir;i<nums.size();i++){
                if(nums[i]>nums[0]){
                    res=false;
                    break;
                }
            }
        }
        return res;
    }
};
