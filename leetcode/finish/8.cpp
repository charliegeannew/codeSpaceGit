/*************************************************************************
* File Name: 8.cpp
* Creat Time: 2021年04月14日 星期三 15时35分23秒
* Author :Charliegean
* Mail :wht905@gmail.com
*************************************************************************/
#include <iostream>

using namespace std;

#define MAXNUM 2147483647
#define NUM 214748364
#define MINNUM -2147483648
int myAtoi(string s);
int main()
{
    string s="-2147483648";
    cout<<"s===="<<s<<endl;
    cout<<"result ===== "<<myAtoi(s)<<endl;
    return 0;
}
int myAtoi(string s){
    int MAXNUM=2147483647;
    int MINNUM=-2147483648;
    int NUM=214748364;
    int res=0,sign=0,startSign=0;
    int len=s.length();
    for(int i=0;i<len;i++){
        if(s[i]==' '){
            if(startSign==1){
                break;
            }
            continue;
        }
        else if(s[i]-'0'>=0 & s[i]-'9'<=0){
            int temp=s[i]-'0';
            startSign=1;
            if(res>NUM){
                if(sign==1|sign==0){
                    res=MAXNUM;
                }
                else{
                    res=MINNUM;
                    sign=1;
                }
                break;
            }
            else if(res==NUM){
                if(sign==1&temp>=7){
                    res=MAXNUM;
                    break;
                }
                else if(sign==0&temp>=7){
                    res=MAXNUM;
                break;
                }
                else if(sign==-1&temp>=8){
                    res=MINNUM;
                    sign=1;
                    break;
                }
                else{
                    res*=10;
                    res+=temp;
                }
            }
            else{
                res*=10;
                res+=temp;
            }
        }
        else if(s[i]=='-'){
            if(startSign==1){
                break;
            }
            else{
                startSign=1;
            }
            if(sign==0){
                sign=-1;
            }
            else {
                res=0;
                break;
            }
        }
        else if(s[i]=='+'){
            if(startSign==1){
                break;
            }
            else{
                startSign=1;
            }
            if(sign==-1){
                res=0;
                break;
            }
            else if(sign==1){
                res=0;
                break;
            }
            else{
                sign=1;
            }
        }
        else{
            break;
        }
    }
    if(sign==0){
        sign=1;
    }
    return res*sign;
}
