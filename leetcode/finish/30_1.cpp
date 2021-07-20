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
    /* string s="wordwordbestgoodgoodgoodbestwordword"; */
    /* vector<string>words={"best","word","good","good","word"}; */
    /* string s="aaaaaaaa"; */
    /* vector<string> words={"aa","aa","aa"}; */
    string s="abababababa";
    vector<string> words={"ababa","babab"};
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
    int len=words[0].length();
    int wordsNum=words.size();
    int sumWordLen=wordsNum*len;
    /* for(int i=0;i<=s.length()-sumWordLen;i++){ */
    for(int i=0;i<=0;i++){
        vector<int>tempFlag(wordsNum,0);
        for(int ii=0;ii<wordsNum;ii++){
            tempFlag[ii]=0;
        }
        int tempIndex=0;
        int firstIndex=0;
        for(int j=firstIndex;j<=s.length()-len;){
            string tempS=s.substr(j,len);
            cout<<"i,j,tempS,tempIndex === "<<firstIndex<<','<<j<<','<<tempS<<','<<tempIndex<<endl;
            for(int ii=0;ii<wordsNum;ii++){
                cout<<tempFlag[ii]<<' ';
            }
            cout<<endl<<"**************************************"<<endl;
            int k=0;
            for(k=0;k<wordsNum;k++){
                if(words[k]==tempS){
                    if(tempFlag[k]==0){
                        tempIndex++;
                        tempFlag[k]=1;
                        break;
                    }
                }
            }
            if(k==wordsNum){
                firstIndex++;
                j=firstIndex;
                tempIndex=0;
                for(int ii=0;ii<wordsNum;ii++){
                    tempFlag[ii]=0;
                }
            }
            else{
                if(tempIndex==wordsNum){
                    res.push_back(firstIndex);
                    firstIndex+=1;
                    j=firstIndex;
                tempIndex=0;
                for(int ii=0;ii<wordsNum;ii++){
                    tempFlag[ii]=0;
                }
                    //i+=len-1;
                    //break;
                }
                else{
                    j+=len;
                }
            }
        }
    } 
    return res;
}
