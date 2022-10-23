/*************************************************************************
*File Name: 2200.cpp
*Author: Charliegean
*wht905@gmail.com
*Created Time: Fri Oct 21 17:14:38 2022
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
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int>temp;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==key){
                temp.push_back(i);
          //      cout<<i<<endl;
            }
        }
        //cout<<nums.size()<<endl;
        vector<int>res;
        int now=0;
        for(int i=0;i<temp.size();i++){
            if(temp[i]+k<now){
                continue;
            }
            int fir=now>temp[i]-k?now:temp[i]-k;
            int sec=temp[i]+k>nums.size()-1?nums.size()-1:temp[i]+k;
            //cout<<fir<<' '<<sec<<endl;
            for(int j=fir;j<=sec;j++){
                res.push_back(j);
            }
            now=sec+1;
        }
        return res;
    }
};
