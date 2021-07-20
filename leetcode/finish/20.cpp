/*************************************************************************
* File Name: 20.cpp
* Creat Time: 2021年04月19日 星期一 17时24分49秒
* Author :Charliegean
* Mail :wht905@gmail.com
*************************************************************************/
#include <iostream>
#include <vector>

using namespace std;

bool isValid(string s);
int main()
{
    string s="([])]";
    cout<<"s === "<<s<<endl;
    cout<<"result === "<<endl<<isValid(s)<<endl;
    return 0;
}
bool isValid(string s){
    bool res=true;
    vector<char> queue;
    int index=0;
    for(int i=0;i<s.length();i++){
        cout<<"inde xi s ==="<<index<<endl;
        if(index==0){
            queue.push_back(s[i]);
            index++;
        }
        else{
            if(queue[index-1]=='('&&s[i]==')'){
                queue.pop_back();
                index--;
            }
            else if(queue[index-1]=='['&&s[i]==']'){
                queue.pop_back();
                index--;
            }
            else if(queue[index-1]=='{'&&s[i]=='}'){
                queue.pop_back();
                index--;
            }
            else{
                queue.push_back(s[i]);
                index++;
            }
        }

    }
    if(index!=0){
        res=false;
    }
    return res;
}
