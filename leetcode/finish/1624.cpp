/*************************************************************************
*File Name: 1624.cpp
*Author: Charliegean
*wht905@gmail.com
*Created Time: Sat Oct 15 19:23:12 2022
 ************************************************************************/
#include <iostream>

using namespace std;
class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int>arr(26,-1);
        int res=-1;
        for(int i=0;i<s.length();i++){
            if(arr[s[i]-'a']>=0){
                int temp=i-arr[s[i]-'a']-1;
                res=res>temp?res:temp;
            }
            else{
                arr[s[i]-'a']=i;
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

