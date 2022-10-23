/*************************************************************************
*File Name: 1640.cpp
*Author: Charliegean
*wht905@gmail.com
*Created Time: Sat Oct 15 21:03:30 2022
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
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        bool res=true;
        map<int,int>dic;
        for(int i=0;i<pieces.size();i++){
            for(int j =0;j<pieces[i].size();j++){
                dic.insert(pair<int,int>(pieces[i][j],i));
            }
        }
        for(int i=0;i<arr.size();){
            if(dic.find(arr[i])==dic.end()){
                res=false;
                break;
            }
            else{
                int ind=dic[arr[i]];
                for(int j=0;j<pieces[ind].size();j++){
                    if(pieces[ind][j]!=arr[i+j]){
                        res=false;
                        break;
                    }
                }
                if(res){
                    i=i+pieces[ind].size();
                }
                else{
                    break;
                }
            }
        }
        return res;
    }
};
