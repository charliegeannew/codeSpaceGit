/*************************************************************************
*File Name: 1913.cpp
*Author: Charliegean
*wht905@gmail.com
*Created Time: Wed Oct 19 22:01:26 2022
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
    int maxProductDifference(vector<int>& nums) {
        int res=0;
        int firmax=nums[0],secmax=nums[0];
        int firmin=nums[0],secmin=nums[0];
        bool firmaxf=false,secmaxf=false;
        bool firminf=false,secminf=false;
        for(int n:nums){
            if(!firmaxf){
                firmax=n;
                firmaxf=true;
            }
            else{
                int temp=firmax;
                if(firmax<n){
                    firmax=n;
                }
                else{
                    temp=n;
                }
                if(!secmaxf){
                    secmax=temp;
                    secmaxf=true;
                }
                else{
                    secmax=secmax>temp?secmax:temp;
                }
            }
            if(!firminf){
                firmin=n;
                firminf=true;
            }
            else{
                int temp=firmin;
                if(firmin>n){
                    firmin=n;
                }
                else{
                    temp=n;
                }
                if(!secminf){
                    secmin=temp;
                    secminf=true;
                }
                else{
                    secmin=secmin>temp?temp:secmin;
                }
            }
        }
        res=(firmax*secmax-firmin*secmin);
        return res;
    }
};
