/*************************************************************************
* File Name: 48.cpp
* Creat Time: 2021年09月25日 星期六 15时20分33秒
* Author :Charliegean
* Mail :wht905@gmail.com
*************************************************************************/
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

void rotate(vector<vector<int>>&matrix);
void printVec(vector<int> vec,string vecName);
void print2DVec(vector<vector<int>> vec,string vecName);
int main(int argc,char ** argv)
{
    cout << "Hello world" << endl;
    /* vector<vector<int>>nums={{1,2,3},{4,5,6},{7,8,9}}; */
    /* vector<vector<int>>nums={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}}; */
    vector<vector<int>>nums={{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    print2DVec(nums,"input nums");
    rotate(nums);
    /* vector<vector<int>>res=permute(nums); */
    /* print2DVec(res,"res is "); */
    return 0;
}
void rotate(vector<vector<int>>&matrix){
    int N=matrix.size();
    for(int i=0;i<int(N/2);i++){
        cout<<"i === "<<i<<endl;
        for(int j=i;j<N-i-1;j++){
            cout<<"j=== "<<j<<endl;
            /* for(int i=0;i<4;i++){ */
                vector<int> befoIndex={i,j};
                vector<int> nextIndex={j,N-1-i};
                int befoTemp=matrix[befoIndex[0]][befoIndex[1]];
                int nextTemp=matrix[nextIndex[0]][nextIndex[1]];
                for(int ii=1;ii<=4;ii++){
                    matrix[nextIndex[0]][nextIndex[1]]=befoTemp;
                    befoTemp=nextTemp;
                    befoIndex[0]=nextIndex[0];
                    befoIndex[1]=nextIndex[1];
                    nextIndex[0]=befoIndex[1];
                    nextIndex[1]=N-1-befoIndex[0];
                    nextTemp=matrix[nextIndex[0]][nextIndex[1]];
                }
            /* } */
        }
    }
    print2DVec(matrix,"res ");
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
