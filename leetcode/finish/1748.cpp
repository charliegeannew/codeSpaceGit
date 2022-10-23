/*************************************************************************
*File Name: 1748.cpp
*Author: Charliegean
*wht905@gmail.com
*Created Time: Sun Oct 16 17:33:37 2022
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
    int sumOfUnique(vector<int>& nums) {
        map<int,bool>dic;
        int res=0;
        for(int n:nums){
            if(dic.find(n)==dic.end()){
                res+=n;
                dic.insert(pair<int,bool>(n,true));
            }
            else{
                if(dic[n]){
                    res-=n;
                    dic[n]=false;
                }
            }
        }
        return res;
    }
};
