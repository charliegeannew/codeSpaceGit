/*************************************************************************
*File Name: 1805.cpp
*Author: Charliegean
*wht905@gmail.com
*Created Time: Wed Oct 19 11:44:25 2022
 ************************************************************************/
#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world" << endl;
    return 0;
}

class Solution {
public:
    int numDifferentIntegers(string word) {
        int res=0;
        map<string,bool>dic;
        for(int i=0;i<word.size();){
            if(word[i]-'0'>=0&&word[i]-'9'<=0){
                int j=i+1;
                for(;j<word.size();j++){
                    if(word[j]-'0'<0||word[j]-'9'>0){
                        break;
                    }
                }

                int k=i;
                for(;k<j;k++){
                    if(word[k]!='0'){
                        break;
                    }
                }
                string temp=word.substr(k,j-k);
                if(dic.find(temp)==dic.end()){
                    dic.insert(pair<string,bool>(temp,true));
                    res++;
                }
                i=j;
            }
            else{
                i++;
            }
        }
        return res;
    }
};
