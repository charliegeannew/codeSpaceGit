/*************************************************************************
*File Name: 1704.cpp
*Author: Charliegean
*wht905@gmail.com
*Created Time: Fri Oct 14 22:05:55 2022
 ************************************************************************/
#include <iostream>

using namespace std;
class Solution {
public:
    bool halvesAreAlike(string s) {
        bool res=true;
        int bef=0;
        for(int i=0;i<s.length()/2;i++){
            if(s[i]=='a'||s[i]=='A'||s[i]=='e'||s[i]=='E'||s[i]=='i'){
                bef++;
            }
            else if(s[i]=='I'||s[i]=='o'||s[i]=='O'||s[i]=='u'||s[i]=='U'){
                bef++;
            }
        }
        for(int i=s.length()/2;i<s.length();i++){
            if(s[i]=='a'||s[i]=='A'||s[i]=='e'||s[i]=='E'||s[i]=='i'){
                bef--;
            }
            else if(s[i]=='I'||s[i]=='o'||s[i]=='O'||s[i]=='u'||s[i]=='U'){
                bef--;
            }
        }
        if(bef==0){
            res=true;
        }
        else{
            res=false;
        }
        return res;
    }
};

int main()
{
    cout << "Hello world" << endl;
    return 0;
}

