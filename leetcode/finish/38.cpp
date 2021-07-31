/*************************************************************************
* File Name: 38.cpp
* Creat Time: 2021年07月28日 星期三 00时06分26秒
* Author :Charliegean
* Mail :wht905@gmail.com
*************************************************************************/
#include <iostream>
#include <string>

using namespace std;

string countAndSay(int n);
int main(int argc,char ** argv)
{
    cout << "Hello world" << endl;
    int n=10;
    cout<<"n is:"<<endl<<n<<endl;
    string res;
    res=countAndSay(n);
    cout<<"res is "<<endl;
    cout<<res<<endl;
    return 0;
}
string countAndSay(int n){
    string befStr="1",res="1";
    while(1){
        if(n<=1){
            break;
        }
        res="";
        for(int i=0;i<befStr.length();){
            int index=1;
            for(;i+index<befStr.length() & befStr[i]==befStr[i+index];index++);
            res+=to_string(index)+befStr[i];
            i+=index;
        }
        befStr=res;
        n--;
    }
    return res;
}
