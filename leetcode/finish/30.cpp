/*************************************************************************
* File Name: 30.cpp
* Creat Time: 2021年04月20日 星期二 22时47分00秒
* Author :Charliegean
* Mail :wht905@gmail.com
*************************************************************************/
#include <iostream>
#include <vector>

using namespace std;

vector<int> findSubstring(string s,vector<string>& words);
int main()
{
    string s="wordwordbestgoodgoodgoodbestwordword";
    vector<string>words={"best","word","good","good","word"};
    /* string s="aaaaaaaa"; */
    /* vector<string> words={"aa","aa"}; */
    /* string s="abababababa"; */
    /* vector<string> words={"ababa","babab"}; */
    vector<int>res;
    res=findSubstring(s,words);
    cout<<"s === "<<s<<endl;
    for(int i=0;i<words.size();i++){
        cout<<words[i]<<' ';
    }
    cout<<endl;
    cout<<"result is "<<endl;
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<' ';
    }
    cout<<endl;
    return 0;
}
vector<int> findSubstring(string s,vector<string>& words){
    vector <int> res;
    vector<int>index;
    vector<int>flag;
    int len=words[0].length();
    if(len*words.size()>s.length()){
        return res;
    }
    vector<string> tempWords;
    vector<int> wordsNumList;
    for(int i=0;i<words.size();i++){
        int j=0;
        for(j=0;j<tempWords.size();j++){
            if(words[i]==tempWords[j]){
                wordsNumList[j]++;
                break;
            }
        }
        if(j==tempWords.size()){
            tempWords.push_back(words[i]);
            wordsNumList.push_back(1);
        }
    }
    for(int j=0;j<=s.length()-len;j++){
        for(int i=0;i<tempWords.size();i++){
            int k=0;
            for(k=0;k<len;k++){
                if(tempWords[i][k]!=s[j+k]){
                    break;
                }
            }
            if(k==len){
                index.push_back(j);
                flag.push_back(i);
            }
        }
    }
    int tempWordsNum=tempWords.size();
    for(int i=0;i<=index.size()-tempWordsNum;i++){
        vector<int> tempFlag=wordsNumList;
        tempFlag[flag[i]]--;
        int k=1;
        int kIndexBef=0,kIndexNow=1;
        while(k<words.size()&&kIndexNow+i<index.size()){
        /* cout<<"i,k,kIndex is "<<i<<','<<k<<","<<kIndexNow<<endl; */
        /* for(int ii=0;ii<tempFlag.size();ii++){ */
        /*     cout<<tempFlag[ii]<<' '; */
        /* } */
        /* cout<<endl; */
            if(index[i+kIndexNow]-index[i+kIndexBef]<len){
                kIndexNow++;
            }
            else if(index[i+kIndexNow]-index[i+kIndexBef]==len){
                if(tempFlag[flag[i+kIndexNow]]>0){
                    tempFlag[flag[i+kIndexNow]]--;
                    k++;
                    kIndexBef=kIndexNow;
                    kIndexNow++;
                }
                else{
                    break;
                }
            }
            else{
                break;
            }
        }
        if(k==words.size()){
            res.push_back(index[i]);
        }
    }
    return res;
}
