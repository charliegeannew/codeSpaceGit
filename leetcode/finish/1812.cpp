/*************************************************************************
*File Name: 1812.cpp
*Author: Charliegean
*wht905@gmail.com
*Created Time: Wed Oct 19 11:47:18 2022
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
    bool squareIsWhite(string coordinates) {
        bool res=(coordinates[0]-'a'+coordinates[1]-'1')%2==1;
        return res;
    }
};
