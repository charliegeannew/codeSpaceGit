/*************************************************************************
*File Name: 1614.cpp
*Author: Charliegean
*wht905@gmail.com
*Created Time: Sat Oct 15 19:19:11 2022
 ************************************************************************/
#include <iostream>

using namespace std;
class Solution {
public:
    int maxDepth(string s) {
        int ma=0;
        int temp=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                temp++;
                ma=ma>temp?ma:temp;
            }
            else if(s[i]==')'){
                temp--;
            }
        }
        return ma;
    }
};

int main()
{
    cout << "Hello world" << endl;
    return 0;
}

