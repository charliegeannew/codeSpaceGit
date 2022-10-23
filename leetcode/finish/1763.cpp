/*************************************************************************
*File Name: 1763.cpp
*Author: Charliegean
*wht905@gmail.com
*Created Time: Wed Oct 19 11:02:26 2022
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
    string longestNiceSubstring(string s) {
        string res;
        bool flag=false;
        for(int i=0;i<s.length();i++){

            vector<int>arr(26,0);
            if(s[i]-'a'>=0&&s[i]-'z'<=0){
                arr[s[i]-'a']++;
            }
            else{
                arr[s[i]-'A']+=2;
            }
            for(int j=i+1;j<s.length();j++){
                if(s[j]-'a'>=0&&s[j]-'z'<=0){
                    if(arr[s[j]-'a']==2 || arr[s[j]-'a']==0){
                        arr[s[j]-'a']+=1;
                    }
                }
                else{
                    if(arr[s[j]-'A']==1 || arr[s[j]-'A']==0){
                        arr[s[j]-'A']+=2;
                    }
                }
                flag=true;
                for(int k=0;k<26;k++){
                    if(arr[k]==1||arr[k]==2){
                        flag=false;
                    }
                }
                if(flag){
                    if(res.length()<j-i+1){
                        res=s.substr(i,j-i+1);
                    }
                }
            }
        }
        return res;
    }
};
