/*************************************************************************
* File Name: 944.cpp
* Creat Time: 2022年03月23日 星期三 18时23分16秒
* Author :Charliegean
* Mail :wht905@gmail.com
*************************************************************************/
#include <iostream>

using namespace std;

int main(int argc,char ** argv)
{
    cout << "Hello world" << endl;
    return 0;
}
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        bool flag=false;
        int res=0;
        int n=strs.size();
        if(n>1){
            for(int i=0;i<strs[0].length();i++){
                for(int j=1;j<n;j++){
                    if(strs[j][i]-strs[j-1][i]<0){
                        res++;
                        break;
                    }
                }
               
            }
        }
        return res;
    }
};
