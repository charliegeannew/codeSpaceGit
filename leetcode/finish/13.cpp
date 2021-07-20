/*************************************************************************
* File Name: 13.cpp
* Creat Time: 2021年04月17日 星期六 16时03分41秒
* Author :Charliegean
* Mail :wht905@gmail.com
*************************************************************************/
#include <iostream>

using namespace std;

int romanToInt(string s);
int main()
{
    string s="MCMXCIV";
    cout<<"s===== "<<s<<endl;
    cout<<"result===="<<romanToInt(s)<<endl;
    return 0;
}
int romanToInt(string s){
    int res=0;
    int indexNum=0;
    int len=s.length();
    for(int i=0;i<len;i++){
        if(s[i]=='M'){
            res+=1000;
        }
        else if(s[i]=='D'){
            res+=500;
        }
        else if(s[i]=='C'){
            if(i+1<len){
                if(s[i+1]=='M'){
                    res+=900;
                    i++;
                }
                else if(s[i+1]=='D'){
                    res+=400;
                    i++;
                }
                else{
                    res+=100;
                }
            }
            else{
                res+=100;
            }
        }
        else if(s[i]=='L'){
            res+=50;
        }
        else if(s[i]=='X'){
            if(i+1<len){
                if(s[i+1]=='C'){
                    res+=90;
                    i++;
                }
                else if(s[i+1]=='L'){
                    res+=40;
                    i++;
                }
                else{
                    res+=10;
                }
            }
            else{
                res+=10;
            }
        }
        else if(s[i]=='V'){
            res+=5;
        }
        else if(s[i]=='I'){
            if(i+1<len){
                if(s[i+1]=='X'){
                    res+=9;
                    i++;
                }
                else if(s[i+1]=='V'){
                    res+=4;
                    i++;
                }
                else{
                    res++;
                }
            }
            else{
                res++;
            }
        }
        else{
            cout<<"error"<<endl;
        }
    }
    return res;
}
