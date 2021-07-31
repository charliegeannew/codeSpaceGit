/*************************************************************************
* File Name: 35.cpp
* Creat Time: 2021年07月27日 星期二 23时13分32秒
* Author :Charliegean
* Mail :wht905@gmail.com
*************************************************************************/
#include <iostream>
#include <vector>

using namespace std;

int searchInsert(vector<int>&nums,int target);
int main(int argc,char ** argv)
{
    cout << "Hello world" << endl;
    /* vector<int> tVec={1,3,5,6}; */
    vector<int> tVec={1};
    int target=0;
    cout<<"tVec is "<<endl;
    for(int i=0;i<tVec.size();i++){
        cout<<tVec[i]<<' ';
    }
    cout<<endl;
    cout<<"target is "<<target<<endl;
    int res;
    res=searchInsert(tVec,target);
    cout<<"res is "<<res<<endl;
    return 0;
}
int searchInsert(vector<int>&nums,int target){
    int res=-1;
    int foreIndex=0,endIndex=nums.size()-1;
    while(1){
        if(foreIndex>endIndex){
            break;
        }
        /* else if(foreIndex==endIndex){ */
        /*     res=foreIndex; */
        /*     break; */
        /* } */
        if(target==nums[foreIndex]){
            res=foreIndex;
            break;
        }
        if(target==nums[endIndex]){
            res=endIndex;
            break;
        }
        int midIndex=(int)((foreIndex+endIndex)/2);
        cout<<"foreindex,midIndex,endindex is "<<foreIndex<<','<<midIndex<<','<<endIndex<<endl;
        if(target==nums[midIndex]){
            res=midIndex;
            break;
        }
        else if(target>nums[midIndex]){
            foreIndex=midIndex+1;
        }
        else{
            endIndex=midIndex-1;
        }
    }
    cout<<"res,foreIndex,endIndex==="<<res<<','<<foreIndex<<','<<endIndex<<endl;
    if(res<0){
        res=endIndex+1;
        
    }
    return res;
}
