/*************************************************************************
* File Name: 44.cpp
* Creat Time: 2021年07月29日 星期四 00时42分24秒
* Author :Charliegean
* Mail :wht905@gmail.com
*************************************************************************/
#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Solution{
public:
    vector<vector<int>> flag;
    bool isMatch(string s,string p);
    bool isMatchFun(string s,string p);
    void printVector(vector<vector<int>>flag);
    void initFlag(string s,string p);
};
int main(int argc,char ** argv)
{
    cout << "Hello world" << endl;
    /* string s="aaabc",p="aaa**??**"; */
    /* string s="b",p="?*?"; */
    /* string s="abcecd",p="*a*cd"; */
    /* string s="aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"; */
    /* string p="*aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa*"; */
    /* string s="babbba",p="*a***a"; */
    string s="mississippi",p="m??*ss*?i*pi";
    cout<<"s is "<<endl<<s<<endl;
    cout<<"p is "<<endl<<p<<endl;
    Solution sol;
    bool res;
    res=sol.isMatch(s,p);
    cout<<"res is "<<res<<endl;
    return 0;
}
bool Solution::isMatch(string s,string p){
    this->initFlag(s,p);
    bool res=this->isMatchFun(s,p);
    return res;
}
bool Solution::isMatchFun(string s,string p){
    bool res=false;
    int sLen=s.length(),pLen=p.length();
    if(sLen==0){
        if(pLen==0){
            res=true;
        }
        else{
            res=true;
            for(int i=0;i<pLen;i++){
                if(p[i]!='*'){
                    res=false;
                    break;
                }
            }
        }
    }
    else if(pLen==0){
        res=false;
    }
    else{
        if(p[pLen-1]=='*'){
            bool sSubP=false,sPSub=false;
            int initFlag=0;
            if(sLen-2>=0){
                if(this->flag[pLen-1][sLen-2]==0){
                    sSubP=false;
                }
                else if(this->flag[pLen-1][sLen-2]==1){
                    sSubP=true;
                }
                else{
                    sSubP=isMatchFun(s.substr(0,sLen-1),p);
                    this->flag[pLen-1][sLen-2]=(int)(sSubP);
                }
                initFlag++;
            }
            if(pLen-2>=0){
                if(this->flag[pLen-2][sLen-1]==0){
                    sPSub=false;
                }
                else if(this->flag[pLen-2][sLen-1]==1){
                    sPSub=true;
                }
                else{
                    sPSub=isMatchFun(s,p.substr(0,pLen-1));
                    this->flag[pLen-2][sLen-1]=(int)(sPSub);
                }
                initFlag+=2;
            }
            if(initFlag==1){
                sPSub=isMatchFun(s,p.substr(0,pLen-1));
            }
            else if(initFlag==2){
                sSubP=isMatchFun(s.substr(0,sLen-1),p);
            }
            else if(initFlag==0){
                sPSub=isMatchFun(s,p.substr(0,pLen-1));
                sSubP=isMatchFun(s.substr(0,sLen-1),p);
            }
            if(sSubP |sPSub){
                res=true;
            }
            else{
                res=false;
            }
        }
        else if(p[pLen-1]=='?'|p[pLen-1]==s[sLen-1]){
            if(pLen-2>=0&sLen-2>=0){
                if(this->flag[pLen-2][sLen-2]==1){
                    res=true;
                }
                else if(this->flag[pLen-2][sLen-2]==0){
                    res=false;
                }
                else{
                    bool sSubPSub=isMatchFun(s.substr(0,sLen-1),p.substr(0,pLen-1));
                    res=sSubPSub; 
                    this->flag[pLen-2][sLen-2]=(int)(sSubPSub);
                }
                /* else if(isMatchFun(s.substr(0,sLen-1),p.substr(0,pLen-1))){ */
                /*     res=true; */
                /* } */
                /* else{ */
                /*     res=false; */
                /* } */
            }
            else if(isMatchFun(s.substr(0,sLen-1),p.substr(0,pLen-1))){
                res=true;
            }
            else{
                res=false;
            }
        }
        else{
            /* cout<<"777777777777777777777777"<<endl; */
            res=false;
        }
        this->flag[pLen-1][sLen-1]=int(res);
        /* cout<<"else begin!"<<endl; */
    }
    return res;
}
void Solution::initFlag(string s,string p){
    for(int i=0;i<p.length()+1;i++){
        vector<int>temp(s.length()+1,-1);
        this->flag.push_back(temp);
    }
}
void Solution::printVector(vector<vector<int>>flag){
    cout<<"flag is "<<endl;
    for(int i=0;i<flag.size();i++){
        for(int j=0;j<flag[i].size();j++){
            if(flag[i][j]>=0){
                cout<<flag[i][j]<<'\t';
            }
            else{
                cout<<'*'<<'\t';
            }
        }
        cout<<endl;
    }
}
