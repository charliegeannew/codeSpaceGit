/*************************************************************************
*File Name: 1684.cpp
*Author: Charliegean
*wht905@gmail.com
*Created Time: Fri Oct 14 17:57:51 2022
 ************************************************************************/
#include <iostream>

using namespace std;
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int res=0;
        vector<int>arr(26,0);
        for(char c:allowed){
            arr[c-'a']++;
        }
        for(int i=0;i<words.size();i++){
            bool flag=true;
            for(int j=0;j<words[i].length();j++){
                if(arr[words[i][j]-'a']<=0){
                    flag=false;
                    break;
                }
            }
            if(flag){
                res++;
            }
        }
        return res;
    }
};

int main()
{
    cout << "Hello world" << endl;
    return 0;
}

