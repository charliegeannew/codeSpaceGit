/*************************************************************************
* File Name: 49.cpp
* Creat Time: 2021年09月25日 星期六 17时50分32秒
* Author :Charliegean
* Mail :wht905@gmail.com
*************************************************************************/
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

vector<vector<string>>groupAnagrams(vector<string>strs);
void printVec(vector<string> vec,string vecName);
void print2DVec(vector<vector<string>> vec,string vecName);
int main(int argc,char ** argv)
{
    cout << "Hello world" << endl;
    /* vector<vector<int>>nums={{1,2,3},{4,5,6},{7,8,9}}; */
    /* vector<vector<int>>nums={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}}; */
    vector<vector<string>>nums;
    print2DVec(nums,"input nums");
    /* print2DVec(res,"res is "); */
    return 0;
}
vector<vector<string>>groupAnagrams(vector<string>strs){
    vector<vector<string>> res;
    vector<int> flag(26,0);
}
void printVec(vector<string> vec,string vecName){
    cout<<"================= "<<vecName<<" ================ "<<endl;
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<'\t';
    }
    cout<<endl;
}
void print2DVec(vector<vector<string>> vec,string vecName){
    cout<<"================= "<<vecName<<" ================ "<<endl;
    for(int i=0;i<vec.size();i++){
        for(int j=0;j<vec[i].size();j++){
            cout<<vec[i][j]<<'\t';
        }
        cout<<endl;
    }

}
