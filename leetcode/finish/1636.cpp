/*************************************************************************
*File Name: 1636.cpp
*Author: Charliegean
*wht905@gmail.com
*Created Time: Sat Oct 15 20:54:49 2022
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
    vector<int> frequencySort(vector<int>& nums) {
        struct tem{
            int num;
            int freq;
        };
        vector<tem>arr;
        map<int,int>dic;
        int ind=0;
        for(int n:nums){
            if(dic.find(n)!=dic.end()){
                arr[dic[n]].freq++;
            }
            else{
                dic.insert(pair<int,int>(n,ind++));
                struct tem temp;
                temp.num=n;
                temp.freq=1;
                arr.push_back(temp);
            }
        }
        sort(arr.begin(),arr.end(),[](struct tem a,struct tem b){
            if(a.freq==b.freq){
                return a.num>b.num;
            }
            else{
                return a.freq<b.freq;
            }
        });
        ind=0;
        for(int i=0;i<arr.size();i++){
            for(int j=0;j<arr[i].freq;j++){
                nums[ind++]=arr[i].num;
            }
        }
        return nums;
    }
};
