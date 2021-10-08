/*************************************************************************
* File Name: 45.cpp
* Creat Time: 2021年09月14日 星期二 18时55分34秒
* Author :Charliegean
* Mail :wht905@gmail.com
*************************************************************************/
#include <iostream>
#include <vector>

using namespace std;

int jump(vector<int>& nums);
int main(int argc,char ** argv)
{
    cout << "Hello world" << endl;
    vector<int> nums={2,3,0,1,4};
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<'\t';
    }
    cout<<endl;
    cout<<"the result is "<<jump(nums)<<endl;
    return 0;
}
int jump(vector<int>& nums){
    int res=nums.size()*2;
    int maxNum=res;
    if(nums.size()==1){
        res=0;
    }
    else{
        vector<int> flag(nums.size(),maxNum);
        flag[nums.size()-1]=0;
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]==0){
                continue;
            }
            else{
                int tempMin=maxNum;
                for(int j=1;i+j<nums.size() & j<=nums[i];j++){
                    if(tempMin>flag[i+j]){
                        tempMin=flag[i+j];
                    }
                }
                flag[i]=tempMin+1;
            }

        }
        for(int i=0;i<nums.size();i++){
            cout<<flag[i]<<' ';
        }
        cout<<endl;
        res=flag[0];
    }
    return res;
}
