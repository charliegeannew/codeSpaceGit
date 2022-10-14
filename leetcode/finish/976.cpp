/*************************************************************************
* File Name: 976.cpp
* Creat Time: 2022年10月12日 星期三 15时44分13秒
* Author :Charliegean
* Mail :wht905@gmail.com
*************************************************************************/
#include <iostream>

using namespace std;

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
                int res=0;
                        sort(nums.begin(),nums.end());
                        for(int i=nums.size()-1;i>=2;i--){
                            if(nums[i-1]+nums[i-2]>nums[i]){
                                                res=nums[i-1]+nums[i-2]+nums[i];
                                                                break;
                                                                            
                            }
                                    
                        }
                                return res;
                                    
    }
    
};
int main(int argc,char ** argv)
{
    cout << "Hello world" << endl;
    return 0;
}

