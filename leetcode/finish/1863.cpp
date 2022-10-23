/*************************************************************************
*File Name: 1863.cpp
*Author: Charliegean
*wht905@gmail.com
*Created Time: Wed Oct 19 16:02:41 2022
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
    int subsetXORSum(vector<int>& nums) {
        int res=0;
        int n=1;
        for(int i=0;i<nums.size();i++){
            n*=2;
        }
        for(int i=0;i<n;i++){
            int temp=0;
            vector<int>flag(nums.size(),0);
            int ind=i;
            for(int j=0;j<nums.size();j++){
                flag[j]=ind%2;
                ind/=2;
                if(flag[j]==1){
                    temp=temp^nums[j];
                }
            }
            res+=temp;
        }
        return res;
    }
};
