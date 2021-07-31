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
int main(int argc,char ** argv)
{
    cout << "Hello world" << endl;
    vector<int> tVec={3,1};
    for(int i=0;i<tVec.size();i++){
        cout<<tVec[i]<<' ';
    }
    cout<<endl;
    int target=1;
    cout<<"target is "<<target<<endl;
    int res=search(tVec,target);
    /* int res=beSearch(tVec,0,N-1,target); */
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
    /* cout<<"in search function foreIndex,endIndex === "<<foreIndex<<","<<endIndex<<endl; */
    if(foreIndex>endIndex){
        return res;
    }
    else if(foreIndex==endIndex ){
        if(nums[foreIndex]==target){
            return foreIndex;
        }
        else{
            return res;
        }
    }
    int midIndex=(int)((foreIndex+endIndex)/2);
    if(nums[foreIndex]<nums[midIndex]){
        res=beSearch(nums,foreIndex,midIndex,target);
        if(res>=0){
            return res+foreIndex;
        }
        vector<int>tempVec;
        for(int i=midIndex+1;i<=endIndex;i++){
            tempVec.push_back(nums[i]);
            /* cout<<nums[i]<<' '; */
        }
        /* cout<<endl; */
        /* res=midIndex+search(tempVec,target)+1; */
        res=search(tempVec,target);
        if(res>=0){
            res+=1+midIndex;
        }
    }
    else{
        res=beSearch(nums,midIndex,endIndex,target);
        if(res>=0){
            return res+midIndex;
        }
        vector<int>tempVec;
        for(int i=0;i<=midIndex;i++){
            tempVec.push_back(nums[i]);
            /* cout<<nums[i]<<' '; */
        }
        /* cout<<endl; */
        /* res=search(tempVec,target)+foreIndex; */
        res=search(tempVec,target);
        if(res>=0){
            res+=foreIndex;
        }
        
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
            cout<<"target, "<<target<<','<<nums[foreIndex]<<','<<nums[endIndex]<<endl;
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
