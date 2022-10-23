/*************************************************************************
*File Name: 1758.cpp
*Author: Charliegean
*wht905@gmail.com
*Created Time: Sun Oct 16 19:48:49 2022
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
    int minOperations(string s) {
        int res=0;
        int le=0,ri=0;
        for(int i=0;i<s.length();i++){
            if(i%2==0){
                if(s[i]=='0'){
                    ri++;
                }
                else{
                    le++;
                }
            }
            else{
                if(s[i]=='0'){
                    le++;
                }
                else{
                    ri++;
                }
            }
        }
        res=le>ri?ri:le;
        return res;
    }
};
