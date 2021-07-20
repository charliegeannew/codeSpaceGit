/*************************************************************************
*File Name: piC.cpp
*Author:Charliegean
*wht905@gmail.com
*Created Time: Tue Mar 30 10:42:47 2021
 ************************************************************************/
#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <ctime>

using namespace std;

long numStep[6]={100,1000,10000,100000,1000000,10000000};
int main(int argc,char*argv[])
{
    double step;
    int index,numSize=6;
    double *piList,*timeList;
    piList=(double*)malloc(sizeof(double)*numSize);
    timeList=(double*)malloc(sizeof(double)*numSize);
    time_t begin,end;
    for(int index=0;index<numSize;index++){
        begin=clock();
        double x,pi,sum=0;
        step=1.0/(double)numStep[index];
        for(int i=0;i<numStep[index];i++){
            x=(i+0.5)*step;
            sum+=4.0/(1+x*x);
        }
        pi=step*sum;
        end=clock();
        double runTime=double(end-begin)/CLOCKS_PER_SEC;
        timeList[index]=runTime;
        piList[index]=pi;
    }
    
    cout<<setprecision(20)<<endl;
    for(int i=0;i<numSize;i++){
        cout<<"pi is "<<piList[i]<<endl;
    }
    for(int i=0;i<numSize;i++){
        cout<<"runtime is "<<timeList[i]<<endl;
    }
    return 0;
}

