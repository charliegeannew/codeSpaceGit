/*************************************************************************
* File Name: 11.cpp
* Creat Time: 2021年04月16日 星期五 22时51分36秒
* Author :Charliegean
* Mail :wht905@gmail.com
*************************************************************************/
#include <iostream>
#include <vector>

using namespace std;

int maxArea(vector<int>height);
int main()
{
    vector<int> height={1,8,6,2,5,4,8,3,7};
    cout<<"vector is"<<endl;
    for(int i=0;i<height.size();i++){
        cout<<height[i]<<' ';
    }
    cout<<endl<<"result is "<<endl;
    cout<<maxArea(height)<<endl;
    return 0;
}
int maxArea(vector<int>height){
    int res=0;
    int len=height.size();
    int i=0,j=len-1;
    while(i<j){
        int temp=j-i;
        if(height[i]<height[j]){
            temp*=height[i];
            i++;
        }
        else{
            temp*=height[j];
            j--;
        }
        res=res<temp?temp:res;
    }
    return res;
}
