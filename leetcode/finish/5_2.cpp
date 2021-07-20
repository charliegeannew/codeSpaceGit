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
    string s="babad";
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
            int j=0;
            while(1){
                cout<<"j==="<<j<<endl;
                if(i-j>=0 & i+j<len){
                    string tempS=s.substr(i-j,j*2+1);
                    cout<<"tempS ==== "<<tempS<<endl;
                    if(ifPalindrome(tempS)>subLen){
                        subSting=tempS;
                        subLen=j*2;
                    }
                    if(i+1<len){
                        if(s[i]==s[i+1]){
                            tempS=s.substr(i-j,2*j+2);
                            if(ifPalindrome(tempS)>subLen){
                                subSting=tempS;
                                subLen=j*2+1;
                            }
                        }
                    }
                }
                else{
                    break;
                }
                j++;
            }
        }
    }
    if(subLen==0){
        subSting=s[0];
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
