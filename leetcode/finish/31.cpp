/*************************************************************************
* File Name: 31.cpp
* Creat Time: 2021年04月21日 星期三 20时25分25秒
* Author :Charliegean
* Mail :wht905@gmail.com
*************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void nextPermulation(vector<int>&nums);
int main()
{
    vector<int> nums={1,2,6,8,7,2};
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<' ';
    }
    cout<<endl;
    nextPermulation(nums);
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<' ';
    }
    cout<<endl;

    return 0;
}
void nextPermulation(vector<int>&nums){
    int flag=0;
    if(nums.size()>1){
        for(int i=nums.size()-1;i>0;i--){
            for(int j=i-1;j>=0;j--){
                for(int k=i;k>j;k--){
                    if(nums[k]>nums[j]){
                        flag=1;
                        int temp=nums[k];
                        nums[k]=nums[j];
                        nums[j]=temp;
                        cout<<"j,k == "<<nums[j]<<','<<nums[k]<<endl;
                        for(int r=0;r<(int)((i-j)/2);r++){
                            int temp=nums[j+r+1];
                            nums[j+r+1]=nums[i-r];
                            nums[i-r]=temp;

                        }
                        break;
                    }
                }
                if(flag==1){
                    break;
                }
            }
            if(flag==1){
                break;
            }
        }
        if(flag==0){
            sort(nums.begin(),nums.end());
        }
    }
}
