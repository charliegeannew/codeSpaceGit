/*************************************************************************
* File Name: 33.cpp
* Creat Time: 2021年07月26日 星期一 22时29分50秒
* Author :Charliegean
* Mail :wht905@gmail.com
*************************************************************************/
#include <iostream>
#include <vector>

using namespace std;

vector<int> getRandomNumVec(int N,int k);
int search(vector<int>&nums,int target);
int beSearch(vector<int>&nums,int foreIndex,int endIndex,int target);
/* int beSearch(vector<int>&nums,int target); */
int main(int argc,char ** argv)
{
    cout << "Hello world" << endl;
    /* vector<int> tVec={4,5,6,7,0,1,2}; */
    vector<int> tVec={1,3};
    for(int i=0;i<tVec.size();i++){
        cout<<tVec[i]<<' ';
    }
    cout<<endl;
    int target=1;
    cout<<"target is "<<target<<endl;
    int res=search(tVec,target);
    cout<<"the res is "<<res<<endl;
    return 0;
}
vector<int> getRandomNumVec(int N,int k){
    vector<int> res;
    for(int i=0;i<N-k;i++){
        res.push_back(i+k);
    }
    for(int i=N-k;i<N;i++){
        res.push_back(i-N+k);
    }
    return res;
}
int search(vector<int>&nums,int target){
    int res=-1;
    int foreIndex=0,endIndex=nums.size()-1;
    int midIndex=(int)((foreIndex+endIndex)/2);
    if(foreIndex>endIndex){
        return -1;
    }
    else if(foreIndex==endIndex ){
        if(nums[foreIndex]==target){
            return foreIndex;
        }
        else{
            return res;
        }
    }
    if(target==nums[midIndex]){
        return midIndex;
    }
    if(nums[foreIndex]<nums[midIndex]){
        res=beSearch(nums,foreIndex,midIndex-1,target);
        if(res>=0){
            return res;
        }
        vector<int>tempVec;
        for(int i=midIndex+1;i<=endIndex;i++){
            tempVec.push_back(nums[i]);
        }
        res=search(tempVec,target);
        if(res>=0){
            res+=midIndex+1;
        }
    }
    else{
        res=beSearch(nums,midIndex+1,endIndex,target);
        if(res>=0){
            return res+midIndex+1;
        }
        vector<int>tempVec;
        for(int i=0;i<midIndex;i++){
            tempVec.push_back(nums[i]);
            cout<<nums[i]<<endl;
        }
        res=search(tempVec,target);
    }
    return res;
}
int beSearch(vector<int>&nums,int foreIndex,int endIndex,int target){
    int res=-1;
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
    return res;
}
