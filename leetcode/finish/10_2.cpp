/*************************************************************************
* File Name: 10.cpp
* Creat Time: 2021年04月14日 星期三 18时38分26秒
* Author :Charliegean
* Mail :wht905@gmail.com
*************************************************************************/
#include <iostream>

using namespace std;
int flagArr[20][30];
bool isMatch(string s,string p);
int main()
{
    //string s="aaaaaaaaaaaaaab",p="a*a*a*a*a*a*a*a*a*a*c*";
    string s="aab",p="ab*a*";
    //string s="mississippi",p="mis*is*ip*.";
    cout<<"s==="<<s<<endl;
    cout<<"p==="<<p<<endl;
    for(int i=0;i<20;i++){
        for(int j=0;j<30;j++){
            flagArr[i][j]=-1;
        }
    }
    cout<<"{";
    for(int i=0;i<20;i++){
        cout<<"{";
        for(int j=0;j<29;j++){
            cout<<flagArr[i][j]<<',';
        }
        cout<<flagArr[i][29];
        cout<<"},"<<endl;
    }
    //*/
    //cout<<s.substr(1,s.length()-1).length()<<endl;
    bool res=isMatch(s,p);
    cout<<"res === "<<res<<endl;
    return 0;
}
bool isMatch(string s,string p){
    bool flag=true;
    int sLen=s.length();
    int pLen=p.length();
    /*cout<<"&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&"<<endl;
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
        int pIndex=pLen-1;
        int sIndex=sLen-1;
        if(pIndex>0){
            if(p[pIndex]=='*'){
                //cout<<"111"<<endl;
                string subS=s.substr(0,sLen-1);
                string subP=p.substr(0,pLen-2);
                int flagSubSP=flagArr[sLen-1][pLen];
                if(flagSubSP==-1){
                    flagSubSP=isMatch(subS,p);
                    flagArr[sLen-1][pLen]=flagSubSP;
                }
                int flagSubSSubP=flagArr[sLen-1][pLen-2];
                if(flagSubSSubP==-1){
                    flagSubSSubP=isMatch(subS,subP);
                    flagArr[sLen-1][pLen-2]=flagSubSSubP;
                }
                int flagSSubP=flagArr[sLen][pLen-2];
                if(flagSSubP==-1){
                    flagSSubP=isMatch(s,subP);
                    flagArr[sLen][pLen-2]=flagSSubP;
                }
                cout<<"**************************************"<<endl;
                cout<<"S,P==="<<s<<','<<p<<endl;
                cout<<"subS,subP==="<<subS<<','<<subP<<endl;
                cout<<"flagSubSP,flagSSubP,flagSubSSubP=-=="<<flagSubSP<<','<<flagSSubP<<','<<flagSubSSubP<<endl;
                cout<<"**************************************"<<endl;
                if(p[pIndex-1]==s[sIndex]||p[pIndex-1]=='.'){
                    //flag=isMatch(subS,p)||isMatch(subS,subP)||isMatch(s,subP);
                    if(flagSubSP+flagSSubP+flagSubSSubP>0){
                        flag=true;
                    }
                    else{
                        flag=false;
                    }
                }
                else if(p[pIndex-1]=='*'){
                    cout<<"error"<<endl;
                    flag=false;
                }
                else{
                    if(flagSSubP==1){
                        flag=true;
                    }
                    else{
                        flag=false;
                    }
                }
            }
            else if(p[pIndex]=='.'){
        //        cout<<"222"<<endl;
                string subS=s.substr(0,sLen-1);
                string subP=p.substr(0,pLen-1);
                if(flagArr[sLen-1][pLen-1]==1){
                    flag=true;
                }
                else if(flagArr[sLen-1][pLen-1]==0){
                    flag=false;
                }
                else{
                    flag=isMatch(subS,subP);
                    flagArr[sLen-1][pLen-1]=flag;
                }
            }
            else{
                if(p[pIndex]==s[sIndex]){
                    string subP=p.substr(0,pLen-1);
                    string subS=s.substr(0,sLen-1);
                    if(flagArr[sLen-1][pLen-1]==1){
                        flag=true;
                    }
                    else if(flagArr[sLen-1][pLen-1]==0){
                        flag=false;
                    }
                    else{
                        flag=isMatch(subS,subP);
                        flagArr[sLen-1][pLen-1]=flag;
                    }
                }
                else{
                    flag=false;
                }
            }
        }
        else{
            if(sLen==1){
                if(p[0]=='.'||p[0]==s[0]){
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
    flagArr[sLen][pLen]=flag;
    return flag;
}
