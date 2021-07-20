/*************************************************************************
* File Name: 32.cpp
* Creat Time: 2021年04月22日 星期四 18时41分39秒
* Author :Charliegean
* Mail :wht905@gmail.com
*************************************************************************/
#include <iostream>

using namespace std;

int longwatValidParentheses(string s);
int main()
{
    string s=")((()))";
    cout<<"s==== "<<s<<endl;
    cout<<"*************************"<<endl;
    int res=longwatValidParentheses(s);
    cout<<"*************************"<<endl;
    cout<<"res === "<<res<<endl;
    return 0;
}
int longwatValidParentheses(string s){
    int res=0;
    int befIndex=0,nowIndex=0,temp=0;
    int len=s.length();
    while(befIndex<len){
        temp=0;
        cout<<"bef,now === "<<befIndex<<','<<nowIndex<<endl;
        for(nowIndex=befIndex;nowIndex<len;nowIndex++){
            if(s[nowIndex]=='('){
                temp++;
            }
            else if(s[nowIndex]==')'){
                if(temp==0){
                    cout<<"end"<<endl;
                    if(res<nowIndex-befIndex){
                        res=nowIndex-befIndex;
                    }
                    befIndex++;
                    break;
                }
                else{
                    temp--;
                }
            }
        }
        /* nowIndex=befIndex; */
    }
    return res;
}
