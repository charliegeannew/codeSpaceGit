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
    string s="baddadaxcfaxcffcxafcxa";
    cout<<"s===="<<s<<endl;
    cout<<"result is "<<endl;
    //cout<<ifPalindrome(s)<<endl;
    cout<<longestPalindrome(s)<<endl;
    return 0;
}
string longestPalindrome(string s){
    int len=s.length();
    string subSting;
    int **lp;
    if(len<=1){
        return s;
    }
    lp=(int**)malloc(sizeof(int*)*len);
    for(int i=0;i<len;i++){
        lp[i]=(int*)malloc(sizeof(int)*len);
        for(int j=0;j<len;j++){
            lp[i][j]=0;
        }
        lp[i][i]=1;
    }
    int subLen=0;
    int subXIndex=0,subYIndex=0;
    for(int j=1;j<len;j++){
        for(int i=0;i+j<len;i++){
            int num=lp[i+1][i+j-1];
            int num1=lp[i+1][i+j];
            int num2=lp[i][i+j-1];
            if(s[i]==s[i+j]&num==j-1){
                cout<<"******************************************"<<endl;
                cout<<"s[i],s[i+j]==="<<s[i]<<','<<s[i+j]<<endl;
                cout<<"i,j=== "<<i<<','<<j<<endl;
                num+=2;
            }
            cout<<"num,num1,num2==="<<num<<','<<num1<<','<<num2<<endl;
            cout<<"string is "<<s.substr(i,j)<<endl;
                cout<<"******************************************"<<endl;
            lp[i][i+j]=max(max(num,num1),num2);
            if(subLen<lp[i][i+j]){
                subLen=lp[i][i+j];
                subXIndex=i;
                subYIndex=i+j;
            }
        }
    }
    cout<<"subLen is"<<subLen<<endl;
    subSting=s.substr(subXIndex,subLen);
    return subSting;
}
