/*************************************************************************
* File Name: 28.cpp
* Creat Time: 2021年04月20日 星期二 16时49分47秒
* Author :Charliegean
* Mail :wht905@gmail.com
*************************************************************************/
#include <iostream>
#include <string>

using namespace std;

int strStr(string haystack,string needle);
int main()
{
    string heystack="aabaaabaaac",needle="aabaaac";
    cout<<"heystack === "<<heystack<<endl<<"needle === "<<needle<<endl;
    cout<<"result is "<<endl<<strStr(heystack,needle)<<endl;
    return 0;
}
int strStr(string haystack,string needle){
    int res=-1;
    int lenH=haystack.length(),lenN=needle.length();
    if(lenN>lenH){
        return res;
    }
    else if(lenN==0){
        return 0;
    }
    for(int i=0;i<=lenH-lenN;i++){
        int j=0;
        int k=0;
        for(j=0;j<lenN;j++){
            if(haystack[i+j]!=needle[j]){
                break;
            }
            if(k==0&&haystack[i+j]==needle[0]){
                k=j;
            }
        }
        cout<<"i,k=== "<<i<<','<<k<<endl;
        if(j==lenN){
            res=i;
            break;
        }
        else if(k>1){
            i+=k-1;
        }
        
    }
    return res;
}

