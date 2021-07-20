/*************************************************************************
*File Name: pi.cpp
*Author:Charliegean
*wht905@gmail.com
*Created Time: Tue May 11 09:35:33 2021
 ************************************************************************/
#include <iostream>
#include <mpi.h>
#include <cstring>
#include <stdlib.h>
#include <iomanip>

using namespace std;

int main(int argc,char*argv[])
{
    int myRank=0;
    MPI_Comm myWorld;
    int groupSize;
    long numStep[6]={1000000,1000,10000,100000,1000000,10000000};
    double step;
    int numSize=6;
    double *piList,*timeList;
    piList=(double*)malloc(sizeof(double)*numSize);
    timeList=(double*)malloc(sizeof(double)*numSize);
    MPI_Init(NULL,NULL);
    MPI_Comm_dup(MPI_COMM_WORLD,&myWorld);
    MPI_Comm_rank(myWorld,&myRank);
    MPI_Comm_size(myWorld,&groupSize);
    for(int index=0;index<numSize;index++){
        double *x=(double*)malloc(sizeof(double)*groupSize); 
        double *sum=(double*)malloc(sizeof(double)*groupSize); 
        double *pi=(double*)malloc(sizeof(double)*groupSize); 
        for(int i=0;i<groupSize;i++){
            sum[i]=0;
            pi[i]=0;
            x[i]=0;
        }
        step=1.0/(double)numStep[index];
        for(int i=myRank;i<numStep[index];i+=groupSize){
            x[myRank]=(i+0.5)*step;
            sum[myRank]+=4.0/(1+x[myRank]*x[myRank]);
        }
        for(int i=0;i<groupSize;i++){
            pi[i]=step*sum[i];
        }
        if(myRank!=0){
            MPI_Send(&pi[myRank],1,MPI_DOUBLE,0,0,myWorld);
        }
        else{
            double temp=0;
            piList[index]=pi[0];
            for(int i=1;i<groupSize;i++){
                MPI_Recv(&temp,1,MPI_DOUBLE,i,0,myWorld,MPI_STATUS_IGNORE);
                piList[index]+=temp;
            }
        }
    }

    MPI_Finalize();
    if(myRank==0){
        cout<<setprecision(20)<<endl;
        for(int i=0;i<numSize;i++){
            cout<<"pi is "<<piList[i]<<endl;
        }
    }
    return 0;
}

