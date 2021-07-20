/*************************************************************************
* File Name: 10.cpp
* Creat Time: 2021年04月14日 星期三 18时38分26秒
* Author :Charliegean
* Mail :wht905@gmail.com
*************************************************************************/
#include <iostream>

using namespace std;
int flagArr[30][30]={-1};
bool isMatch(string s,string p);
int main()
{
    string s="aaaaaaaaaaaaaab",p="a*a*a*a*a*a*a*a*a*a*c";
    cout<<"s==="<<s<<endl;
    cout<<"p==="<<p<<endl;
    for(int i=0;i<30;i++){
        for(int j=0;j<30;j++){
            cout<<flagArr[i][j]<<' ';
        }
        cout<<endl;
    }
    //cout<<s.substr(1,s.length()-1).length()<<endl;
    //bool res=isMatch(s,p);
    //cout<<"res === "<<res<<endl;
    return 0;
}
bool isMatch(string s,string p){
    bool flag=true;
    int sLen=s.length();
    int pLen=p.length();
    cout<<"&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&"<<endl;
    cout<<"s==="<<s<<endl<<"p===="<<p<<endl;
    cout<<"sLen === "<<sLen<<endl<<"pLen==="<<pLen<<endl;
    cout<<"&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&"<<endl;
    //*/
    if(sLen==0){
        if(pLen==0){
            flag=true;
        }
        else{
            for(int i=0;i<pLen;i++){
                if(p[i]=='.'){
                    if(i+1<pLen){
                        if(p[i+1]=='*'){
                            i++;
                        }
                        else{
                            flag=false;
                            break;
                        }
                    }
                    else{
                        flag=false;
                        break;
                    }
                    continue;
                }
                else if(p[i]!='*'){
                    if(i+1<pLen&&p[i+1]=='*'){
                        i++;
                    }
                    else{
                        flag=false;
                        break;
                    }
                }
            }
        }
    }
    else{
        int pIndex=0;
        int sIndex=0;
        if(pIndex<pLen){
            if(p[pIndex]=='.'){
                if(pIndex+1<pLen){
                    if(p[pIndex+1]=='*'){
                        string subP=p.substr(2,pLen-2);
                        string subS=s.substr(1,sLen-1);
                        if(isMatch(subS,p)||isMatch(subS,subP)||isMatch(s,subP)){
                            flag=true;
                        }
                        else{
                            flag=false;
                        }
                    } 
                    else{
                        string subP=p.substr(1,pLen-1);
                        string subS=s.substr(1,sLen-1);
                        if(isMatch(subS,subP)){
                            flag=true;
                        }
                        else{
                            flag=false;
                        }
                    }
                }
                else{
                    if(sLen==1){
                        flag=true;
                    }
                    else{
                        flag=false;
                    }
                }
            }
            else if(p[pIndex]==s[sIndex]){
               //cout<<"111111"<<endl;
                if(pIndex+1<pLen){
                    if(p[pIndex+1]=='*'){
                        //cout<<"111"<<endl;
                        string subP=p.substr(2,pLen-2);
                        string subS=s.substr(1,sLen-1);
                        /*cout<<"*********************************"<<endl;
                        cout<<"p==="<<p<<endl<<"s==="<<s<<endl;
                        cout<<"subp==="<<subP<<endl<<"subS==="<<subS<<endl;
                        cout<<"*********************************"<<endl;
                        //*/
                        if(isMatch(s,subP)||isMatch(subS,subP)||isMatch(subS,p)){
                            //cout<<"+_+++++++++++++++++++++++"<<endl;
                            flag=true;
                        }
                        else{
                            flag=false;
                        }
                    }
                    else{
                        //cout<<"---------------------------------"<<endl;
                        if(isMatch(s.substr(1,sLen-1),p.substr(1,pLen-1))){
                            flag=true;
                        }
                        else{
                            flag=false;
                        }
                    }
                }
                else{
                    if(sIndex+1<sLen){
                        flag=false;
                    }
                    else{
                        flag=true;
                    }
                }
                //cout<<"22222"<<endl;
            }
            else{
                if(pIndex+1<pLen){
                    if(p[pIndex+1]=='*'&&isMatch(s,p.substr(2,pLen-2))){
                        flag=true;
                    }
                    else{
                        flag=false;
                    }
                }
                else{
                    flag=false;
                }
            }
        }
        else{
            flag=false;
        }
    }
    return flag;
}
