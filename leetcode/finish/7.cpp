/*************************************************************************
* File Name: 7.cpp
* Creat Time: 2021年04月14日 星期三 15时03分52秒
* Author :Charliegean
* Mail :wht905@gmail.com
*************************************************************************/
#include <iostream>

using namespace std;

int reverse(int x);
int main()
{
    int x=1534246469;
    //int x=-0;
    cout<<"x is "<<x<<endl;
    cout<<"result is "<<endl<<reverse(x)<<endl;
    return 0;
}
int reverse(int x){
    int res=0,sign=1;
    int before=0;
    if(x<0){
        if(x==-2147483648){
            return 0;
        }
        sign=-1;
        x*=-1;
    }
    while(1){
        if(x>0){
            int temp=x%10;
            if(res>214748364){
                res=0;
                break;
            }
            res*=10;
            res+=temp;
            x=(int)(x/10);
        }
        else{
            break;
        }
    }
    return res*sign;
}
