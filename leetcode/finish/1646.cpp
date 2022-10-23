/*************************************************************************
*File Name: 1646.cpp
*Author: Charliegean
*wht905@gmail.com
*Created Time: Sat Oct 15 21:11:26 2022
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
    int getMaximumGenerated(int n) {
        int res=0;
        if(n==0){
            res=0;
        }
        else if(n==1){
            res=1;
        }
        else{
            vector<int>arr={0,1};
            for(int i=2;i<=n;i++){
                int temp=arr[i/2];
                if(i%2==1){
                    temp+=arr[i/2+1];
                }
                res=res>temp?res:temp;
                arr.push_back(temp);
            }
        }
        return res;
    }
};
