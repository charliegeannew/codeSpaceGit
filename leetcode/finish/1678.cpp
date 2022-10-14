/*************************************************************************
*File Name: 1678.cpp
*Author: Charliegean
*wht905@gmail.com
*Created Time: Fri Oct 14 17:53:57 2022
 ************************************************************************/
#include <iostream>

using namespace std;
class Solution {
public:
    string interpret(string command) {
        string res;
        for(int i=0;i<command.length();){
            if(command[i]=='G'){
                res+=command[i];
                i++;
            }
            else if(command[i]=='('){
                if(i+1<command.length()){
                    if(command[i+1]==')'){
                        res+='o';
                        i+=2;
                    }
                    else{
                        res+="al";
                        i+=4;
                    }
                }
            }
            else{
                cout<<"error "<<endl;
                i++;
            }
        }
        return res;
    }
};

int main()
{
    cout << "Hello world" << endl;
    return 0;
}

