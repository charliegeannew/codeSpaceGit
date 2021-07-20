/*************************************************************************
* File Name: 4.cpp
* Creat Time: 2021年04月12日 星期一 21时18分28秒
* Author :Charliegean
* Mail :wht905@gmail.com
*************************************************************************/
#include <iostream>
#include <vector>

using namespace std;

double findMedianSortArrays(vector<int>nums1,vector<int>nums2);
int main()
{
    vector<int>nums1={1,3};
    //vector<int>nums2={2,4,6,7,8,9,10,11,12,13,14};
    vector<int>nums2={2};
    cout<<"result is "<<endl;
    cout<<findMedianSortArrays(nums1,nums2)<<endl;
    return 0;
}
double findMedianSortArrays(vector<int>nums1,vector<int>nums2){
    int len1=nums1.size();
    int len2=nums2.size();
    double res=0,numBefore=0,numNow=0;
    int N=len1+len2;
    int i=0,j=0,index=0;
    int M=(int)((N)/2);
    while(1){
        if(index>M|i>=len1|j>=len2){
            break;
        }
        numBefore=numNow;
        if(nums1[i]<nums2[j]){
            numNow=nums1[i++];
        }
        else{
            numNow=nums2[j++];
        }
        index++;
    }
    if(index<=M){
        for(;i<len1;i++){
            numBefore=numNow;
            numNow=nums1[i];
            if(index>=M){
                break;
            }
            index++;
        }
        for(;j<len2;j++){
            numBefore=numNow;
            numNow=nums2[j];
            if(index>=M){
                break;
            }
            index++;
        }
    }
    cout<<"*********************************"<<endl;
    cout<<"i,j== "<<i<<','<<j<<endl;
    cout<<"M==="<<M<<endl;
    cout<<"index==="<<index<<endl;
    cout<<"numBefore,numNow==="<<numBefore<<','<<numNow<<endl;
    cout<<"*********************************"<<endl;
    if(N%2==0){
        res=(numBefore+numNow)/2;           
    }
    else{
        res=numNow;
    }    
    return res;
}
