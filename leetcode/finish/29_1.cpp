/*************************************************************************
* File Name: 29.cpp
* Creat Time: 2021年04月20日 星期二 17时15分27秒
* Author :Charliegean
* Mail :wht905@gmail.com
*************************************************************************/
#include <iostream>

using namespace std;

int divide(int dividend,int divisor);
int main()
{
    int dividend=-2147483648,divisor=2;
    cout<<"dividend/divisor == "<<dividend<<","<<divisor<<endl;
    cout<<"result is "<<divide(dividend,divisor)<<endl;
    return 0;
}
int divide(int dividend,int divisor){
    int res=0;
    int sign=1;
    if(dividend==0){
        return res;
    }
    if(dividend==-2147483648){
        if(divisor>1){
            dividend+=divisor;
            res++;
        }
        else if(divisor==1){
            return dividend;
        }
        else if(divisor==-1){
            return 2147483647;
        }
        else{
            res++;
            dividend-=divisor;
        }
    }
    if(divisor<0){
        sign*=-1;
        divisor*=-1;
    }
    if(divisor==1){
        return dividend*sign;
    }
    if(dividend<0){
        sign*=-1;
        dividend*=-1;
    }
    for(;;res++){
        if(dividend<divisor){
            break;
        }
        else{
            dividend-=divisor;
        }
    }
    return res*sign;
}

