/*************************************************************************
*File Name: testOpenMP.c
*Author:Charliegean
*wht905@gmail.com
*Created Time: Fri Mar 19 18:50:53 2021
 ************************************************************************/
#include <iostream>
#include <stdlib.h>
#include <omp.h>

using namespace std;

int main(int argc,char* argv[])
{
    int i=0,N=16,M=4;
    double *a,*b,*c;
    a=(double*)malloc(sizeof(double)*(N+1));
    b=(double*)malloc(sizeof(double)*(N+1));
    c=(double*)malloc(sizeof(double)*(N+1));
    for(int i=0;i<N+1;i++){
        a[i]=i*0.1;
        b[i]=i*0.1;
        c[i]=i*0.1;
    }
    cout<<"********************************************"<<endl;
    for(int i=0;i<N;i++){
        cout<<a[i]<<' ';
    }
    cout<<endl;
    cout<<"********************************************"<<endl;
    //*/
    int temp=0;
    #pragma omp parallel for num_threads(4)
    for(int i=omp_get_thread_num()*M;i<N+omp_get_thread_num()*M-1;i++){
        temp=omp_get_thread_num();
        if(temp==0){
            a[i]=a[i+1]+1;
        }
        else {
            a[i-M*temp]=a[i+1-M*temp]+1;
        }
        //cout<<"Hello world,with thread NO. "<<omp_get_thread_num()<<" in this thread i== "<<i<<endl;
    }
    for(int i=1;i<=4;i++){
        a[i*M-1]=b[i*M]+1;
        
    }
    for(int i=0;i<4;i++){
        a[i*M]=b[i*M+1]+1;
    }
    for(int i=0;i<N+1;i++){
        b[i]=b[i+1]+1;
    }
    cout<<"********************************************"<<endl;
    for(int i=0;i<N;i++){
        cout<<a[i]<<' ';
    }
    cout<<endl;
    cout<<"bbbbbbbbbbbbbbbbbb"<<endl;
    for(int i=0;i<N;i++){
        cout<<b[i]<<' ';
    }
    cout<<endl;
    cout<<"********************************************"<<endl;
    //*/
    for(int i=0;i<N+1;i++){
        c[i]=c[i+1]+1;
    }
    for(int i=0;i<N;i++){
        if(abs(a[i]-b[i])>1e-10 ){
            if(abs(c[i]-b[i])>1e-10){
                cout<<"error1 !!!!!!!!!!!!!!! then i == "<<i<<endl;
                cout<<a[i]<<' '<<b[i]<<endl;
            }
            else{
                cout<<"error2 !!!!!!!!!!!!!!! then i == "<<i<<endl;
                cout<<a[i]<<' '<<b[i]<<endl;
            }
            //break;
        }
    }
    return 0;
}

