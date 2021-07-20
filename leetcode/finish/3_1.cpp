/*************************************************************************
* File Name: 3.cpp
* Creat Time: 2021年04月12日 星期一 13时18分05秒
* Author :Charliegean
* Mail :wht905@gmail.com
*************************************************************************/
#include <iostream>

using namespace std;
int lengthOfLongestSubstring(string s);
int main()
{
    string s="aabbbcccx";
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
        for(int i=0;i<len;i++){
            string temp;
            temp+=s[i];
            int j=0;
            for(j=1;j<len-i;j++){
                int index=temp.find(s[i+j]);
                cout<<"temp is "<<temp<<endl;
                cout<<"index is "<<index<<endl;
                if(index==-1){
                    temp+=s[i+j];
                }
                else{
                    break;
                }
            }
            if(subLen<temp.length()){
                subLen=temp.length();
            }
        }
        return subLen;
}

