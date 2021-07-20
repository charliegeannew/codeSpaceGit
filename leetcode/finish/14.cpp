/*************************************************************************
* File Name: 14.cpp
* Creat Time: 2021年04月17日 星期六 16时19分24秒
* Author :Charliegean
* Mail :wht905@gmail.com
*************************************************************************/
#include <iostream>
#include <vector>

using namespace std;

string longestCommonPrefix(vector<string>& strs);
int main()
{
    //vector<string> strs={"flower","flow","flight"};
    //vector<string> strs={"dog","rececar","car"};
    vector<string> strs={"flower","flower","flower"};
    int len=strs.size();
    cout<<"strs ==== "<<endl;
    for(int i=0;i<len;i++){
        cout<<strs[i]<<' ';
    }
    cout<<endl;
    cout<<"result ===== "<<endl;
    cout<<longestCommonPrefix(strs)<<endl;
    return 0;
}
string longestCommonPrefix(vector<string>& strs){
    int index=0;
    int len=strs.size();
    int flag=true;
    if(len==0){
        return "";
    }
    while(flag){
        if(index>strs[0].length()){
            flag=false;
        }
        else{
            for(int i=1;i<len;i++){
                if(index>=strs[i].length()){
                    flag=false;
                    break;
                }
                if(strs[0][index]!=strs[i][index]){
                    flag=false;
                    break;
                }
            }
        }
        index++;
    }
    return strs[0].substr(0,index-1);
}
