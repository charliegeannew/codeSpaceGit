/*************************************************************************
*File Name: testOpenMP.c
*Author:Charliegean
*wht905@gmail.com
*Created Time: Fri Mar 19 18:50:53 2021
 ************************************************************************/
#include <iostream>
#include <stdlib.h>
#include <omp.h>
#include <queue>

using namespace std;

int findError(int temp,int*a,int *b);
int main(int argc,char* argv[])
{
    int i=0,N=16,M=4;
    queue<int> q0,q1,q2,q3,q4;
    int a0[4]={1,2,3,0},a1[4]={8,9,10,11},a2[4]={16,17,18,19},a3[4]={24,25,26,27};
    int b0[4]={0},b1[4]={0},b2[4]={0},b3[4]={0};
    int temp=0;
    #pragma omp parallel for num_threads(4)
    for(int i=omp_get_thread_num()*M;i<N+omp_get_thread_num()*M;i++){
        temp=omp_get_thread_num();
        if(temp==0){
            q0.push(i);
        }
        else if(temp==1){
            q1.push(i);
        }
        else if(temp==2){
            q2.push(i);
        }
        else if(temp==3){
            q3.push(i);
        }
        else{
            q4.push(i);
        }
        //cout<<"Hello world,with thread NO. "<<omp_get_thread_num()<<" in this thread i== "<<i<<endl;
    }
    //cout<<"********************************************"<<endl;
    while(!q0.empty()){
        int temp=q0.front();
        if (findError(temp,a0,b0)==1){
            cout<<"error"<<temp<<endl;
        }
        q0.pop();
    }
    //cout<<endl;
    //cout<<"********************************************"<<endl;
    //cout<<"********************************************"<<endl;
    while(!q1.empty()){
        int temp=q1.front();
        if (findError(temp,a1,b1)==1){
            cout<<"error"<<temp<<endl;
        }
        q1.pop();
    }
    //cout<<endl;
    //cout<<"********************************************"<<endl;
    //cout<<"********************************************"<<endl;
    while(!q2.empty()){
        int temp=q2.front();
        if (findError(temp,a2,b2)==1){
            cout<<"error"<<temp<<endl;
        }
        q2.pop();
    }
    //cout<<endl;
    //cout<<"********************************************"<<endl;
    //cout<<"********************************************"<<endl;
    while(!q3.empty()){
        int temp=q3.front();
        if (findError(temp,a3,b3)==1){
            cout<<"error"<<temp<<endl;
        }
        q3.pop();
    }
    //cout<<endl;
    //cout<<"********************************************"<<endl;

    return 0;
}
int findError(int temp,int*a,int *b){
    int flag=1;
    for(int i=0;i<4;i++){
        if(temp==a[i] &b[i]==0){
            flag=0;
            b[i]=1;
            break;
        }
    }
    return flag;
}
