/*************************************************************************
*File Name: 1710.cpp
*Author: Charliegean
*wht905@gmail.com
*Created Time: Sat Oct 15 22:01:21 2022
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
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int res=0;
        sort(boxTypes.begin(),boxTypes.end(),[](vector<int>a,vector<int>b){
            return a[1]>b[1];
        });
        for(int i=0;i<boxTypes.size();i++){
            if(truckSize<=boxTypes[i][0]){
                res+=truckSize*boxTypes[i][1];
                truckSize=0;
                break;
            }
            else{
                res+=boxTypes[i][0]*boxTypes[i][1];
                truckSize-=boxTypes[i][0];
            }
        }
        return res;
    }
};
