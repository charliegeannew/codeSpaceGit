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

bool isMatch(string s,string p);
void printVector(vector<vector<bool>>flag);
int main(int argc,char ** argv)
{
    cout << "Hello world" << endl;
    string s="b",p="?*?";
    cout<<"s is "<<endl<<s<<endl;
    cout<<"p is "<<endl<<p<<endl;
    bool res;
    res=isMatch(s,p);
    cout<<"res is "<<res<<endl;
    return 0;
}
bool isMatch(string s,string p){
    bool res=true;
    vector<vector<bool>> flag;
    int sLen=s.length(),pLen=p.length();
    if(sLen==0){
        if(pLen==0){
            res=true;
        }
        else{
            for(int i=0;i<pLen;i++){
                if(p[i]=='*'){
                    continue;
                }
                else{
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
        for(int i=0;i<pLen;i++){
            vector<bool> temp(sLen,false);
            flag.push_back(temp);
        }
        if(p[0]=='*'){
            for(int i=0;i<sLen;i++){
                flag[0][i]=true;
            }
        }
        else if(p[0]=='?'){
            flag[0][0]=true;
        }
        else if(p[0]==s[0]){
            flag[0][0]=true;
        }
        else{
            res=false;
        }
        printVector(flag);
        for(int i=1;res & i<pLen;i++){
            for(int j=1;j<sLen;j++){
                cout<<"i,j == "<<i-1<<','<<j-1<<" flag is "<<flag[i-1][j-1]<<endl;
                if(flag[i-1][j-1]){
                    if(p[i-1]=='*'){
                        if(p[i]=='*'){
                            for(;j<=sLen;j++){
                                flag[i][j-1]=true;
                            }
                        }
                        else if(p[i]=='?'){
                            flag[i][j-1]=true;
                            flag[i][j]=true;
                        }
                        else if(p[i]==s[j-1]){
                            flag[i][j-1]=true;
                        }
                        else if(p[i]==s[j]){
                            flag[i][j]=true;
                        }
                        else{
                            continue;
                        }
                    }
                    else{
                        if(p[i]=='*'){
                            for(;j<sLen;j++){
                                flag[i][j]=true;
                            }
                        }
                        else if(p[i]=='?'){
                            flag[i][j]=true;
                        }
                        else if(p[i]==s[j]){
                            flag[i][j]=true;
                        }
                        else{
                            flag[i][j]=false;
                        }
                    }
                }
            }
            if(flag[i-1][sLen-1]){
                if(p[i-1]=='*'){
                    if(p[i]=='*'){
                        flag[i][sLen-1]=true;
                    }
                    else if(p[i]==s[sLen-1]|p[i]=='?'){
                        flag[i][sLen-1]=true;
                    }
                }
                else{
                    if(p[i]=='*'){
                        flag[i][sLen-1]=true;
                    }
                } 
            }
        }
        printVector(flag);
        res=flag[pLen-1][sLen-1];
    }
    return res;
}
void printVector(vector<vector<bool>>flag){
    cout<<"flag is "<<endl;
    for(int i=0;i<flag.size();i++){
        for(int j=0;j<flag[i].size();j++){
            cout<<flag[i][j]<<' ';
        }
        cout<<endl;
    }
}
