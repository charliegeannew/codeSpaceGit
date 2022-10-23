/*************************************************************************
*File Name: 1716.cpp
*Author: Charliegean
*wht905@gmail.com
*Created Time: Sat Oct 15 22:09:07 2022
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
    int totalMoney(int n) {
        int res=28*(n/7)+(n/7*(n/7-1)*7)/2;
        for(int i=0;i<n%7;i++){
            res+=(n/7+1+i);
        }
        return res;
    }
};
