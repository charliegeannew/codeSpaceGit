/*************************************************************************
*File Name: 1694.cpp
*Author: Charliegean
*wht905@gmail.com
*Created Time: Fri Oct 14 21:49:38 2022
 ************************************************************************/
#include <iostream>

using namespace std;
class Solution {
public:
    string reformatNumber(string number) {
        string res,temp;
        for(char c:number){
            if(c!=' '&&c!='-'){
                temp+=c;
            }
        }
        if(temp.length()<=3){
            res=temp;
        }
        else if(temp.length()==4){
            res+=temp[0];
            res+=temp[1];
            res+='-';
            res+=temp[2];
            res+=temp[3];
        }
        else if(temp.length()%3==0){
            res+=temp[0];
            res+=temp[1];
            res+=temp[2];
            for(int i=3;i<temp.length();i+=3){
                res+='-';
                res+=temp[i];
                res+=temp[i+1];
                res+=temp[i+2];
            }
        }
        else if(temp.length()%3==1){
            res+=temp[0];
            res+=temp[1];
            res+=temp[2];
            for(int i=3;i<temp.length()-4;i+=3){
                res+='-';
                res+=temp[i];
                res+=temp[i+1];
                res+=temp[i+2];
            }
            res+='-';
            res+=temp[temp.length()-4];
            res+=temp[temp.length()-3];
            res+='-';
            res+=temp[temp.length()-2];
            res+=temp[temp.length()-1];
        }
        else if(temp.length()%3==2){
            res+=temp[0];
            res+=temp[1];
            res+=temp[2];
            for(int i=3;i<temp.length()-2;i+=3){
                res+='-';
                res+=temp[i];
                res+=temp[i+1];
                res+=temp[i+2];
            }
            res+='-';
            res+=temp[temp.length()-2];
            res+=temp[temp.length()-1];
        }
        return res;
    }
};

int main()
{
    cout << "Hello world" << endl;
    return 0;
}

