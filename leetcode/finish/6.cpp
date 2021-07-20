/*************************************************************************
* File Name: 6.cpp
* Creat Time: 2021年04月14日 星期三 13时47分13秒
* Author :Charliegean
* Mail :wht905@gmail.com
*************************************************************************/
#include <iostream>

using namespace std;

int main()
{
    string s="PAYPALISHIRING";
    //string s="A";
    int numRows=5;
    cout<<"s is "<<endl<<s<<endl;
    string convert(string s,int numRows);
    cout<<"result is"<<endl;
    cout<<convert(s,numRows)<<endl;
    return 0;
}
string convert(string s,int numRows){
    string res;
    int subLen=2*numRows-2;
    int len=s.length();
    if(len==0|len==1|numRows==1){
        res=s;
    }
    else{
        cout<<"*********************************"<<endl;
        for(int i=0;i<len;i+=subLen){
            res+=s[i];
            cout<<"res==="<<res<<endl;
        }
        for(int i=1;i<numRows-1;i++){
            for(int j=i;j<len;j+=subLen){
                res+=s[j];
                if(j+subLen-2*i){
                    res+=s[j+subLen-2*i];
                }
            cout<<"res==="<<res<<endl;
            }
        }
        for(int i=numRows-1;i<len;i+=subLen){
            res+=s[i];
            cout<<"res==="<<res<<endl;
        }
        cout<<"*********************************"<<endl;
    }
    return res;
}

