/*************************************************************************
*File Name: 1893.cpp
*Author: Charliegean
*wht905@gmail.com
*Created Time: Wed Oct 19 21:28:55 2022
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
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        bool res=false;
        vector<vector<int>>arr={{left,right}};
        for(int i=0;i<ranges.size();i++){
            if(arr.size()==0){
                res=true;
                break;
            }
            vector<int>rmind;
            vector<vector<int>>ins;
            for(int j=0;j<arr.size();j++){
                if(arr[j][0]>ranges[i][1]||arr[j][1]<ranges[i][0]){
                    continue;
                }
                else if(ranges[i][0]<=arr[j][0]){
                    if(ranges[i][1]>=arr[j][1]){
                        rmind.push_back(j);
                    }
                    else{
                        arr[j][0]=ranges[i][1]+1;
                    }
                }
                else{
                    if(ranges[i][1]>=arr[j][1]){
                        arr[j][1]=ranges[i][0]-1;
                    }
                    else{
                        vector<int>temp={ranges[i][1]+1,arr[j][1]};
                        arr[j][1]=ranges[i][0]-1;
                    }
                }
            }
            for(int j=rmind.size()-1;j>=0;j--){
                arr.erase(arr.begin()+rmind[j]);
            }
            for(int j=0;j<ins.size();j++){
                arr.push_back(ins[j]);
            }
        }
        if(arr.size()==0){
            res=true;
        }
        else{
            res=false;
        }
        return res;
    }
};
