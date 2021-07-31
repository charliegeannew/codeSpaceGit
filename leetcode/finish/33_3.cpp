/*************************************************************************
* File Name: 33.cpp
* Creat Time: 2021年07月26日 星期一 22时29分50秒
* Author :Charliegean
* Mail :wht905@gmail.com
*************************************************************************/
#include <iostream>
#include <vector>

using namespace std;

int search(vector<int>&nums,int target);
int beSearch(vector<int>&nums,int foreIndex,int endIndex,int target);
int main(int argc,char ** argv)
{
    cout << "Hello world" << endl;
    vector<int> tVec={3,1};
    for(int i=0;i<tVec.size();i++){
        cout<<tVec[i]<<' ';
    }
    cout<<endl;
    int target=3;
    cout<<"target is "<<target<<endl;
    int res=search(tVec,target);
    cout<<"the res is "<<res<<endl;
    return 0;
}
int search(vector<int>&nums,int target){
    int res=-1;
    int foreIndex=0,endIndex=nums.size()-1;
    while(1){
        int midIndex=(int)((endIndex+foreIndex)/2);
        cout<<"midIndex === "<<midIndex<<endl;
        if(foreIndex>endIndex){
            break;
        }
        else if(foreIndex==endIndex){
            if(nums[foreIndex]==target){
                res=foreIndex;
            }
            break;
        }
        if(target==nums[midIndex]){
            res=midIndex;
            break;
        }
        if(nums[foreIndex]<nums[midIndex]){
            if(target==nums[midIndex]){
                res=midIndex;
                break;
            }
            else if(target>nums[midIndex]){
                foreIndex=midIndex+1;
            }
            else{
                res=beSearch(nums,foreIndex,midIndex-1,target);
                if(res>=0){
                    res+=foreIndex;
                    break;
                }
                else{
                    foreIndex=midIndex+1;
                }
            }
        }
        else if(nums[foreIndex]==nums[midIndex]){
            if(target==nums[foreIndex]){
                res=foreIndex;
            }
            else if(target==nums[endIndex]){
                res=endIndex;
            }
            else{
                res=-1;
            }
            break;
        }
        else{
            cout<<"2222222222"<<endl;
            if(target==nums[midIndex]){
                res=midIndex;
                break;
            }
            else if(target>nums[midIndex]){
                res=beSearch(nums,midIndex+1,endIndex,target);
                if(res>=0){
                    res+=midIndex+1;
                    break;
                }
                else{
                    endIndex=midIndex-1;
                }
            }
            else{
                endIndex=midIndex-1;
            }
        }
    }
    return res;
}
int beSearch(vector<int>&nums,int foreIndex,int endIndex,int target){
    int res=-1;
    cout<<"in beSearch function,foreIndex,endIndex==="<<foreIndex<<','<<endIndex<<endl;
    for(int i=foreIndex;i<=endIndex;i++){
        cout<<nums[i]<<' ';
    }
    cout<<endl;
    int temp=foreIndex;
    while(1){
        if(foreIndex>endIndex){
            break;
        }
        else if(foreIndex==endIndex){
            if(target==nums[foreIndex]){
                return 0;
            }
            else{
                return -1;
            }
        }
        int midIndex=(int)((foreIndex+endIndex)/2);
        if(target<nums[foreIndex] | target>nums[endIndex]){
            /* cout<<"target, "<<target<<','<<nums[foreIndex]<<','<<nums[endIndex]<<endl; */
            res=-1;
            break;
        }
        else{
            if(target==nums[foreIndex]){
                res=foreIndex-temp;
                break;
            }
            if(target==nums[endIndex]){
                res=endIndex-temp;
                break;
            }
            if(target==nums[midIndex]){
                res=midIndex-temp;
                break;
            }
            else if(target<nums[midIndex]){
                endIndex=midIndex-1;
            }
            else{
                foreIndex=midIndex+1;
            }
        }
    }
    cout<<"in beSearch function the res is "<<res<<endl;
    return res;
}
