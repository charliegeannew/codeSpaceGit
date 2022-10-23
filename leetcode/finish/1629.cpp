/*************************************************************************
*File Name: 1629.cpp
*Author: Charliegean
*wht905@gmail.com
*Created Time: Sat Oct 15 20:45:32 2022
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
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        for(int i=releaseTimes.size()-1;i>=1;i--){
            releaseTimes[i]-=releaseTimes[i-1];
        }
        char c='a'-1;
        int ma=releaseTimes[0];
        for(int n:releaseTimes){
            ma=ma>n?ma:n;
        }
        //cout<<ma<<endl;
        for(int i=0;i<releaseTimes.size();i++){
            //cout<<releaseTimes[i]<<endl;
            if(ma==releaseTimes[i]){
                if(keysPressed[i]-c>0){
                    c=keysPressed[i];
                }
            }
        }
        return c;
    }
};
