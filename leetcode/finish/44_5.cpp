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
    /* string s="aaabc",p="aaa**??**"; */
    string s="babbba",p="*a***a";
    /* string s="mississippi",p="m??*ss*?i*pi"; */
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
            for(int j=0;j<sLen;j++){
                /* cout<<"i,j == "<<i-1<<','<<j<<" flag is "<<flag[i-1][j]<<endl; */
                /* cout<<"222 p["<<i<<"]=== "<<p[i]<<endl; */
                if(flag[i-1][j]){
                    if(p[i-1]=='*'){
                        /* cout<<"111 p["<<i<<"]=== "<<p[i]<<endl; */
                        if(p[i]=='*'){
                            for(;j<sLen;j++){
                                flag[i][j]=true;
                            }
                        }
                        else if(p[i]=='?'){
                            int realNum=0;
                            int ii=0;
                            cout<<"eeeeeeeeeeeeiiiiv === "<<i<<endl;
                            bool tempFlag=true;
                            for(ii=i-1;ii>=0;ii--){
                                cout<<"ii,j,flag == "<<ii<<','<<j<<','<<flag[ii][j]<<endl;
                                if(flag[ii][j]){
                                    if(p[ii]!='*'){
                                        realNum++;
                                        cout<<"when ? the realNum i s "<<realNum<<endl; 
                                        for(int tempIndex=j;tempIndex>=0 ;tempIndex--){
                                            if(flag[ii][tempIndex]){
                                            cout<<"when the tempindex is "<<tempIndex<<endl;
                                                if(j-tempIndex>=realNum){
                                                    tempFlag=true;
                                                    break;
                                                }
                                                else{
                                                    tempFlag=false;
                                                }
                                            }
                                            else{
                                                break;
                                            }
                                        }
                                    }
                                }
                                else{
                                    break;
                                }
                            }
                            if(tempFlag){
                                cout<<"++++++++++++++++++++++++++++++++"<<endl;
                            if(ii>=0){
                                int jj=j;
                                for(;jj>=0;jj--){
                                    if(flag[ii][jj]){
                                        break;
                                    }
                                }
                                if(realNum+1<=j-jj){
                                    flag[i][j]=true;
                                }
                            }
                            else{
                                cout<<"realNum ,j "<<realNum<<','<<j<<endl;
                                if(realNum>j){
                                    flag[i][j]=false;
                                }
                                else{
                                    flag[i][j]=true;
                                }
                            }
                            
                            }
                            else{
                                flag[i][j]=false;
                            }
                        }
                        else if(p[i]==s[j]){
                            int realNum=0;
                            int ii=i-1;
                            bool tempFlag=true;
                            cout<<"222222222222222222222"<<endl;
                            for(ii=i-1;ii>=0;ii--){
                                if(flag[ii][j]){
                                    if(p[ii]!='*'){
                                        realNum++;
                                        cout<<"realNum is "<<endl;
                                        for(int tempIndex=j;tempIndex>=0 ;tempIndex--){
                                            if(flag[ii][tempIndex]){
                                            cout<<"when the tempindex is "<<tempIndex<<endl;
                                                if(j-tempIndex>=realNum){
                                                    tempFlag=true;
                                                    break;
                                                }
                                                else{
                                                    tempFlag=false;
                                                }
                                            }
                                            else{
                                                break;
                                            }
                                        }
                                    }
                                }
                                else{
                                    break;
                                }
                            }
                            /* cout<<"realNum , ii "<<realNum<<','<<ii<<endl; */
                            if(tempFlag){
                            if(ii>=0){
                                int jj=j;
                                /* cout<<j<<endl<<endl; */
                                for(;jj>=0;jj--){
                                    /* cout<<"====jj "<<jj<<endl; */
                                    /* cout<<"000000000 "<<flag[ii][jj]<<endl; */
                                    if(flag[ii][jj]){
                                        break;
                                    }
                                }
                                /* cout<<"realNum ,j-jj "<<realNum<<','<<j-jj<<endl; */
                                if(realNum+1<=j-jj){
                                    flag[i][j]=true;
                                }
                            }
                            else{
                                /* if(realNum>sLen){ */
                                if(realNum>j){
                                    flag[i][j]=false;
                                }
                                else{
                                    flag[i][j]=true;
                                }
                            } 
                            }
                            else{
                                flag[i][j]=false;
                            }
                        }
                        else if(j+1<sLen & p[i]==s[j+1]){
                            flag[i][j+1]=true;
                        }
                        else{
                            continue;
                        }
                    }
                    else{
                        /* cout<<"00000000000000p["<<i<<"]=== "<<p[i]<<"   j  ===  "<<j<<endl; */
                        if(p[i]=='*'){
                            for(;j<sLen;j++){
                                flag[i][j]=true;
                            }
                        }
                        else if(p[i]=='?'&j+1<sLen){
                            /* cout<<"222222222222222222222"<<endl; */
                            /* cout<<"i,j+1========================="<<i<<','<<j<<endl; */
                            flag[i][j+1]=true;
                        }
                        else if(j+1<sLen & p[i]==s[j+1]){
                            flag[i][j+1]=true;
                        }
                        else{
                            /* flag[i][j]=false; */
                        }
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
