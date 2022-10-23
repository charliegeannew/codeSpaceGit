/*************************************************************************
*File Name: 1652.cpp
*Author: Charliegean
*wht905@gmail.com
*Created Time: Sat Oct 15 21:23:45 2022
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
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int>res(code.size(),0);
        if(k>0){
            int temp=0;
            for(int i=0;i<k;i++){
                temp+=code[i];
            }
            for(int i=0;i<code.size();i++){
                temp-=code[i];
                temp+=code[(i+k)%code.size()];
                res[i]=temp;
            }
        }
        else if(k<0){
            k*=-1;
            int temp=0;
            for(int i=0;i<k;i++){
                temp+=code[code.size()-i-1];
            }
            for(int i=code.size()-1;i>=0;i--){
                temp-=code[i];
                temp+=code[(i-k+code.size())%code.size()];
                res[i]=temp;
            }
        }
        return res;
    }
};
