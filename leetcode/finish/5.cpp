/*************************************************************************
* File Name: 5.cpp
* Creat Time: 2021年04月13日 星期二 21时16分37秒
* Author :Charliegean
* Mail :wht905@gmail.com
*************************************************************************/
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

string longestPalindrome(string s);
int ifPalindrome(string s);
int main()
{
    //string s="baddadaxcfaxcffcxafcxa";
    string s="abbd";
    cout<<"s===="<<s<<endl;
    cout<<"result is "<<endl;
    //cout<<ifPalindrome(s)<<endl;
    cout<<longestPalindrome(s)<<endl;
    return 0;
}
string longestPalindrome(string s){
    int len=s.length();
    string subSting;
    int subLen=0,subXIndex=0;
    for(int i=0;i<len;i++){
        int tempOddLen=0;
        int j=0;
        for(j=0;i+j<len &i-j>=0;j++){
            if(s[i-j]!=s[i+j]){
                break;
            }
        }
        tempOddLen=2*j-1;
        int tempEvenLen=0;
        if(i+1<len &&s[i]==s[i+1]){
            for(j=0;i+1+j<len&i-j>=0;j++){
                if(s[i-j]!=s[i+1+j]){
                    break;
                }
            }
            tempEvenLen=j*2;
        }
        cout<<"************************************"<<endl;
        cout<<"i,tempEvenLen,tempOddLen==="<<i<<','<<tempEvenLen<<','<<tempOddLen<<endl;
        cout<<"subLen,subXIndex==="<<subLen<<','<<subXIndex<<endl;
        cout<<"************************************"<<endl;
        if(tempEvenLen>tempOddLen){
            if(subLen<tempEvenLen){
                subLen=tempEvenLen;
                subXIndex=i-(int)(subLen/2)+1;
            }
        }
        else{
            if(subLen<tempOddLen){
                subLen=tempOddLen;
                subXIndex=i-(int)(subLen/2);
            }
        }
        
    }
    subSting=s.substr(subXIndex,subLen);
    return subSting;
}
