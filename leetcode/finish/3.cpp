/*************************************************************************
* File Name: 3.cpp
* Creat Time: 2021年04月12日 星期一 13时18分05秒
* Author :Charliegean
* Mail :wht905@gmail.com
*************************************************************************/
#include <iostream>
#include <string>

using namespace std;

int lengthOfLongestSubstring(string s);
int main()
{
    string s="aaabcdxbbcdefgx";
    cout<<"s===="<<s<<endl;
    cout<<"result is "<<endl;
    cout<<lengthOfLongestSubstring(s)<<endl;
    return 0;
}
int lengthOfLongestSubstring(string s){
    int len=s.length();
    int subLen=0;
    if(len==0 | len ==1){
        return len;
    }
    else{
        int lIndex=0,rIndex=1;
        for(;lIndex<len;){
            if(rIndex<len){
                int tempCIndex=-1;
                for(int i=lIndex;i<rIndex;i++){
                    if(s[rIndex]==s[i]){
                        tempCIndex=i-lIndex;
                        break;
                    }
                }
                cout<<"********************************"<<endl;
                cout<<"s=== "<<s<<endl;
                //cout<<"temp is "<<temp<<endl;
                //cout<<"tempC is "<<tempC<<endl;
                //cout<<"index is "<<tempCIndex<<endl;
                cout<<"lIndex,rIndex ==="<<lIndex<<" "<<rIndex<<endl;
                cout<<"subLen is "<<subLen<<endl;
                cout<<"tempIndex === "<<tempCIndex<<endl;
                cout<<"********************************"<<endl;
                //*/
                if(tempCIndex==-1){
                    rIndex+=1;
                    if(subLen<rIndex-lIndex){
                        subLen=rIndex-lIndex;
                    }
                }
                else{
                    lIndex+=tempCIndex+1;
                    rIndex+=1;
                    if(rIndex==len){
                        if(subLen<rIndex-lIndex){
                            subLen=rIndex-lIndex;
                        }
                    }
                }
            }
            else{
                break;
            }
        }
    }
    return subLen;
}
