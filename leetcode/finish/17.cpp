/*************************************************************************
* File Name: 17.cpp
* Creat Time: 2021年04月19日 星期一 11时40分09秒
* Author :Charliegean
* Mail :wht905@gmail.com
*************************************************************************/
#include <iostream>
#include <vector>

using namespace std;

vector<string> letterCombinations(string digits);
int main()
{
    string digits="8";
    cout<<"*************************"<<endl;
    cout<<"digits === "<<digits<<endl;
    cout<<"res is "<<endl;
    letterCombinations(digits);
    cout<<"*************************"<<endl;
    return 0;
}
vector<string> letterCombinations(string digits){
    vector<string> res;
    int len=digits.length();
    string addChar2To8[7]={"abc","def","ghi","jkl","mno","","tuv"};
    if(len==0){
        return res;
    }
    if(digits[0]=='7'){
        res.push_back("p");
        res.push_back("q");
        res.push_back("r");
        res.push_back("s");
    }
    else if(digits[0]=='9'){
        res.push_back("w");
        res.push_back("x");
        res.push_back("y");
        res.push_back("z");
    }
    else{
        string temp;
        temp=addChar2To8[digits[0]-'2'][0];
        res.push_back(temp);
        temp=addChar2To8[digits[0]-'2'][1];
        res.push_back(temp);
        temp=addChar2To8[digits[0]-'2'][2];
        res.push_back(temp);
    }
    for(int i=1;i<len;i++){
        if(digits[i]=='9'){
            string addChar="wxyz";
            int tempLen=res.size();
            for(int j=0;j<tempLen;j++){
                res[j]+=addChar[0];
            }
            for(int k=1;k<4;k++){
                for(int j=0;j<tempLen;j++){
                    res.push_back(res[j]);
                    res[k*tempLen+j][i]=addChar[k];
                }
            }
        }
        else if(digits[i]=='7'){
            string addChar="pqrs";
            int tempLen=res.size();
            for(int j=0;j<tempLen;j++){
                res[j]+=addChar[0];
            }
            for(int k=1;k<4;k++){
                for(int j=0;j<tempLen;j++){
                    res.push_back(res[j]);
                    res[k*tempLen+j][i]=addChar[k];
                }
            }
        }
        else{
            int tempLen=res.size();
            for(int j=0;j<tempLen;j++){
                res[j]+=addChar2To8[digits[i]-'2'][0];
            }
            for(int k=1;k<3;k++){
                for(int j=0;j<tempLen;j++){
                    res.push_back(res[j]);
                    res[k*tempLen+j][i]=addChar2To8[digits[i]-'2'][k];
                }
            }

        }
    }
    //*/
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<' ';
    }
    cout<<endl;
    return res;
}
