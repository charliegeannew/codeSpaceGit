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
    /* int dividend=-2147483648,divisor=4; */
    int dividend=1,divisor=3;
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
            if(divisor==-2147483648){
                return 1;
            }
            res++;
            dividend-=divisor;
        }
    }
    if(divisor==-2147483648){
        return 0;
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
    int before=divisor,now=divisor,index=1;
    while(1){
        if(dividend<divisor){
            break;
        }
        if(dividend >=now){
            dividend-=now;
            if(now>=1073741824){
                dividend-=now;
                res+=index;
                continue;
            }
            now*=2;
            res+=index;
            index*=2;
        }
        else{
            while(1){
                now/=2;
                index/=2;
                if(index<=1){
                    break;
                }
                while(dividend>=now){
                    dividend-=now;
                    res+=index;
                }
            }
        }
    }
    return res*sign;
}

