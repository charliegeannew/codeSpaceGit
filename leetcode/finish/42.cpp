/*************************************************************************
* File Name: 42.cpp
* Creat Time: 2021年08月02日 星期一 22时55分57秒
* Author :Charliegean
* Mail :wht905@gmail.com
*************************************************************************/
#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int trap(vector<int>&height);
};
void printVector(vector<int>vec);
int main(int argc,char ** argv)
{
    cout << "Hello world" << endl;
    vector<int> height={0,1,0,2,1,0,1,3,2,1,2,1};
    /* vector<int> height={4,2,0,3,2,5}; */
    printVector(height);
    Solution sol;
    int res=sol.trap(height);
    cout<<"res is "<<res<<endl;
    return 0;
}
int Solution::trap(vector<int>&height){
    int res=0;
    int n=height.size();
    if(n>=3){
        int larLef=height[0];
        int larRig=height[n-1];
        for(int i=n-1;i>1;i--){
            if(larRig<height[i]){
                larRig=height[i];
            }
        }
        for(int index=1;index<n-1;index++){
            cout<<"index , height === "<<index<<"          "<<res<<endl;
            if(larLef<larRig){
                if(height[index]<larLef){
                    res+=larLef-height[index];
                }
                else{
                    larLef=height[index];
                }
            }
            else{
                if(height[index]<larRig){
                    res+=larRig-height[index];
                }
            }
            if(height[index+1]==larRig){
                larRig=height[n-1];
                for(int i=n-1;i>index+1;i--){
                    if(larRig<height[i]){
                        larRig=height[i];
                    }
                }
            }
        }
    }
    return res;
}
void printVector(vector<int>vec){
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<'\t';
    }
    cout<<endl;
}

