/*************************************************************************
* File Name: 9.cpp
* Creat Time: 2021年04月14日 星期三 16时52分13秒
* Author :Charliegean
* Mail :wht905@gmail.com
*************************************************************************/
#include <iostream>

using namespace std;

bool isPalidProme(int x);
int main()
{
    //int x=2147483640;
    int x=0;
    cout<<"x==="<<x<<endl;
    cout<<"result ===="<<endl<<isPalidProme(x)<<endl;
    return 0;
}
bool isPalidProme(int x){
    bool flag=false;
    int starttNum=x,reverseNum=0;
    if(x>=0){
        while(starttNum>0){
            int temp=starttNum%10;
            if(reverseNum>=214748364){
                break;
            }
            /*else if(reverseNum==214748364){
                if(temp>=1){
                    break;
                }
                
            }
            //*/
            reverseNum*=10;
            reverseNum+=temp;
            starttNum=(int)(starttNum/10);
        }
        cout<<"reverseNum ==="<<reverseNum<<endl;
        if(reverseNum==x){
            flag=true;
        }
    }
    return flag;
}
