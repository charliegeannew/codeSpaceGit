/*************************************************************************
* File Name: 5.cpp
* Creat Time: 2021年04月13日 星期二 21时16分37秒
* Author :Charliegean
* Mail :wht905@gmail.com
*************************************************************************/
#include <iostream>
#include <string>

using namespace std;

string longestPalindrome(string s);
int ifPalindrome(string s);
int main()
{
    string s="ac";
    cout<<"s===="<<s<<endl;
    cout<<"result is "<<endl;
    //cout<<ifPalindrome(s)<<endl;
    cout<<longestPalindrome(s)<<endl;
    return 0;
}
string longestPalindrome(string s){
    int len=s.length();
    string subSting;
    int subLen=0;
    if(len==0 | len ==1){
        subSting=s;
        subLen=len;
    }
    else{
        for(int i=0;i<len;i++){
            for(int j=i+subLen;j<len;j++){
                string tempS=s.substr(i,j-i);
                if(ifPalindrome(tempS)>0){
                    subSting=tempS;
                    subLen=j-i;
                }
            }
        }
    }
    return subSting;
}
int ifPalindrome(string s){
    int len=s.length();
    for(int i=0;i<len/2;i++){
        /*
        cout<<"i===="<<i<<endl;
        cout<<"flag==="<<flag<<endl;
        cout<<"len==="<<len<<endl;
        cout<<"s[i],s[len-i]==="<<s[i]<<','<<s[len-1-i]<<endl;
        //*/
        if(s[i]!=s[len-1-i]){
            len=0;
            break;
        }
    }
    return len;
}
