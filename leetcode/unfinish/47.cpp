/*************************************************************************
* File Name: 47.cpp
* Creat Time: 2021年09月24日 星期五 21时13分18秒
* Author :Charliegean
* Mail :wht905@gmail.com
*************************************************************************/
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

vector<vector<int>>permute(vector<int>&nums);
void printVec(vector<int> vec,string vecName);
void print2DVec(vector<vector<int>> vec,string vecName);
int main(int argc,char ** argv)
{
    cout << "Hello world" << endl;
    vector<int>nums={1,1,2,1};
    printVec(nums,"input nums");
    vector<vector<int>>res=permute(nums);
    print2DVec(res,"res is ");
    return 0;
}
vector<vector<int>>permute(vector<int>&nums){
    vector<vector<int>>res;
    vector<int>fir={nums[0]};
    res.push_back(fir);
    vector<int>numsSin;
    vector<int> otherVec;
    for(int i=0;i<nums.size();i++){
        bool ifRepeat=true;
        for(int j=0;j<numsSin.size();j++){
            if(nums[i]==nums[j]){
                ifRepeat=false;
                break;
            }
        }
        if(ifRepeat){
            numsSin.push_back(nums[i]);
        }
        else{
            otherVec.push_back(nums[i]);
        }
    }
    
    for(int i=1;i<numsSin.size();i++){
        int N=res.size();
        for(int j=0;j<N;j++){
            vector<int>temp(res[j]);
            res[j].push_back(numsSin[i]);
            for(int index=0;index<i;index++){
                temp.insert(temp.begin()+index,numsSin[i]);
                res.push_back(temp);
                temp.erase(temp.begin()+index);
            }
        }
    }
    int len=res[0].size();
    for(int i=0;i<otherVec.size();i++){
        int N=res.size();
        for(int j=0;j<N;j++){
            vector<int>temp(res[j]);
            res[j].push_back(otherVec[i]);
            for(int index=0;index<len;index++){
                if(temp[index]!=otherVec[i]){
                    temp.insert(temp.begin()+index,otherVec[i]);
                    res.push_back(temp);
                    temp.erase(temp.begin()+index);
                }
            }
        }
    }

    return res;
}
void printVec(vector<int> vec,string vecName){
    cout<<"================= "<<vecName<<" ================ "<<endl;
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<'\t';
    }
    cout<<endl;
}
void print2DVec(vector<vector<int>> vec,string vecName){
    cout<<"================= "<<vecName<<" ================ "<<endl;
    for(int i=0;i<vec.size();i++){
        for(int j=0;j<vec[i].size();j++){
            cout<<vec[i][j]<<'\t';
        }
        cout<<endl;
    }

}
