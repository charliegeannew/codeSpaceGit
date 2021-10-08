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
    string s="babbaabaaabaaababbbabbbabbbbbbaabbbbbabaaaabbbbaaaaaababababaaabbbababbaabbbbbbbbabbbbbabbbbabbbbbabbbbbbbaaabbbbbbbaabbbabbaabbbbaabbbaabaabbaaabbbbaaabbabbbabaabbbbbaababbaabbbaaabbbabaaaabaaaabbbbaba";
    string p="**a****a*b*bab*a*****abb*a*bab*a****b**a**b**a***bbbb**b*b***b**a*b*ba*b**ab*aa*b***a*a****b****bab*a*";
    /* string s="babbba",p="*a***a"; */
    /* string s="mississippi",p="m??*ss*?i*pi"; */
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
    if(this->flag[pLen][sLen]>=0){
        res=(bool)(this->flag[pLen][sLen]);
    }
    else if(sLen==0){
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
                else{
                    this->flag[i][0]=1;
                }
            }
        }
    }
    else if(pLen==0){
        res=false;
    }
    else{
        string sSub=s.substr(0,sLen-1);
        string pSub=p.substr(0,pLen-1);
        if(p[pLen-1]=='*'){
            if(this->flag[pLen][sLen-1]>=0){
                res=(bool)(this->flag[pLen][sLen-1]);
            }
            else{
                res=isMatchFun(sSub,p);
                this->flag[pLen][sLen-1]=(int)(res);
            }
            if(!res){
                if(this->flag[pLen-1][sLen]>=0){
                    res=(bool)(this->flag[pLen-1][sLen]);
                }
                else{
                    res=isMatchFun(s,pSub);
                    this->flag[pLen-1][sLen]=(int)(res);
                }
            }
            if(!res){
                if(this->flag[pLen-1][sLen-1]>=0){
                    res=(bool)(this->flag[pLen-1][sLen-1]);
                }
                else{
                    res=isMatchFun(sSub,pSub);
                    this->flag[pLen-1][sLen-1]=(int)(res);
                }
            }
        }
        else if(p[pLen-1]=='?' | p[pLen-1]==s[sLen-1]){
            if(this->flag[pLen-1][sLen-1]>=0){
                res=(bool)(this->flag[pLen-1][sLen-1]);
            }
            else{
                res=isMatchFun(sSub,pSub);
                this->flag[pLen-1][sLen-1]=(int)(res);
            }
        }
        else{
            res=false;
        }
    }
    this->flag[pLen][sLen]=(int)(res);
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
