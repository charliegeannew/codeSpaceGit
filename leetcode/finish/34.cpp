/*************************************************************************
* File Name: 34.cpp
* Creat Time: 2021年07月27日 星期二 02时35分12秒
* Author :Charliegean
* Mail :wht905@gmail.com
*************************************************************************/
#include <iostream>
#include <vector>

using namespace std;

vector<int> searchRange(vector<int>&nums,int target);
int main(int argc,char ** argv)
{
    cout << "Hello world" << endl;
    /* vector<int> tVec={5,7,7,8,8,10}; */
    vector<int> tVec={1,4};
    int target=4;
    vector<int> res;
    res=searchRange(tVec,target);
    cout<<"tVec is :"<<endl;
    for(int i=0;i<tVec.size();i++){
        cout<<tVec[i]<<' ';
    }
    cout<<endl;
    cout<<"res is:"<<endl;
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<' ';
    }
    cout<<endl;
    return 0;
}
vector<int> searchRange(vector<int>&nums,int target){
    vector<int> res={0,0};
    res[1]=nums.size()-1;
    int foreIndex=0,endIndex=nums.size()-1;
    int flag=-1;
    while(1){
        if(res[0]>res[1]){
            break;
        }
        if(target==nums[res[0]]){
            flag=res[0];
            break;
        }
        if(target==nums[res[1]]){
            flag=res[1];
            break;
        }
        if(target>nums[res[1]]|target<nums[res[0]]){
            break;
        }
        else{
            int midIndex=(int)((res[0]+res[1])/2);
            if(target==nums[midIndex]){
                flag=midIndex;
                break;
            }
            else if(target>nums[midIndex]){
                res[0]=midIndex+1;
            }
            else{
                res[1]=midIndex-1;
            }
        }
    }
    cout<<"flag is "<<flag<<endl;
    if(flag>=0){
        res[0]=flag;
        foreIndex=0;
        endIndex=flag-1;
        while(1){
            if(foreIndex>endIndex){
                break;
            }
            int midIndex=(int)((foreIndex+endIndex)/2);
            if(nums[midIndex]==target){
                endIndex=midIndex-1;
                res[0]=midIndex;
            }
            else if(target>nums[midIndex]){
                foreIndex=midIndex+1;
            }
            else{
                cout<<"error!"<<endl;
            }
        }
        res[1]=flag;
        foreIndex=flag+1;
        endIndex=nums.size()-1;
        while(1){
            if(foreIndex>endIndex){
                break;
            }
            int midIndex=(int)((foreIndex+endIndex)/2);
            if(nums[midIndex]==target){
                res[1]=midIndex;
                foreIndex=midIndex+1;
            }
            else if(target<nums[midIndex]){
                endIndex=midIndex-1;
            }
            else{
                cout<<"error!"<<endl;
            }
        }
    }
    else{
        res[0]=-1;
        res[1]=-1;
    }
    return res;
}
