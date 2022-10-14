/*************************************************************************
*File Name: 940.cpp
*Author: Charliegean
*wht905@gmail.com
*Created Time: Fri Oct 14 17:19:04 2022
 ************************************************************************/
#include <iostream>

using namespace std;

class Solution {
public:
    int distinctSubseqII(string s) {
        int res=0;
        int ma=10e8+7;
        vector<int>last(26,-1);
        vector<int>arr(26,0);
        last[s[0]-'a']=0;
        arr[s[0]-'a']=1;
        for(int i=1;i<s.length();i++){
            int temp=1;
            for(int j=0;j<26;j++){
                if(last[j]!=-1){
                    temp+=arr[j];
                    temp%=ma;
                }
            }
            arr[s[i]-'a']=temp;
            last[s[i]-'a']=i;
        }
        for(int i=0;i<arr.size();i++){
            res+=arr[i];
            res=res%ma;
        }
        return res;
    }
};
int main()
{
    cout << "Hello world" << endl;
    return 0;
}

