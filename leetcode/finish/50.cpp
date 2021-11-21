/*************************************************************************
* File Name: 50.cpp
* Creat Time: 2021年10月17日 星期日 12时15分42秒
* Author :Charliegean
* Mail :wht905@gmail.com
*************************************************************************/
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

double myPow_1(double x,int n);
double myPow_2(double x,int n);
class Solution{
public:
    vector<double> tempRes;
    double myPow(double x,int n){
        double res=0;
        if(abs(x)<1e-32){
            res= 0;
        }
        else{
            if(n>0){
                for(int i=0;i<=n;i++){
                    this->tempRes.push_back(0);
                }
                res=myPowTemp(x,n);
            }
            else if(n==0){
                res=1;
            }
            else{
                if(n==-2147483648){
                    res=0;
                }
                else{
                    n=-1*n;
                    for(int i=0;i<=n;i++){
                        this->tempRes.push_back(0);
                    }
                    res=myPowTemp(x,n);
                    res=1/res;
                }
            }
        }
        return res;
    }
    double myPowTemp(double x,int n){
        double res=1;
        cout<<"n === "<<n<<endl;
        cout<<"temp.zise "<<this->tempRes.size()<<endl;
        if(n==0){
            res=1;
        }
        else if(n==1){
            res=x;
        }
        else{
            double tempLe=this->tempRes[int(n/2)];
            if(abs(tempLe)<=1e-32){
                tempLe=myPowTemp(x,int(n/2));
            }
            res=tempLe*tempLe;
            if(n%2==1){
                res*=x;
            }
        }
        this->tempRes[n]=res;
        return res;
    }
};
double myPow_3(double x,int n);
int main(int argc,char ** argv)
{
    cout << "Hello world" << endl;
    double x=-3;
    int n=-5;
    Solution sol;
    cout<<"pow("<<x<<','<<n<<")=====";
    /* cout<<myPow_2(x,n)<<endl; */
    cout<<sol.myPow(x,n)<<endl;
    return 0;
}
double myPow_1(double x,int n){
    double res=1;
    int flag=1;
    int myN=n;
    if(myN<0){
        myN=n*-1;
        flag=-1;
    }
    for(int i=0;i<myN;i++){
        res*=x;
    }
    if(flag==-1){
        res=1/res;
    }
    return res;
}
double myPow_2(double x,int n){
    double res=1;
    int flag=1;
    if(n<0){
        flag=-1;
        n=-1*n;
    }
    if(n==0){
        res=1;
    }
    else{
        vector<double>vec={x};
        vector<double>vecK={1};
        int k=0;
        for(int i=1;i<=n;){
            i=i*2;
            k++;
            vec.push_back(vec[k-1]*vec[k-1]);
            vecK.push_back(i);
        }
        for(int i=0;i<k;i++){
            cout<<vec[i]<<'\t';
        }
        cout<<endl;
        for(int i=0;i<k;i++){
            cout<<vecK[i]<<'\t';
        }
        cout<<endl;
        int tempN=n;
        int tempIndex=0;
        while(tempN>0){
            tempIndex++;
            if(tempIndex>10){
                break;
            }
            /* cout<<"tempN == "<<tempN<<endl; */
            int index=k;
            for(;index>=0;index--){
                if(tempN>=vecK[index]){
                    break;
                }
            }
            /* cout<<"index is "<<index<<endl; */
            res=res*vec[index];
            tempN-=vecK[index];
        }
    }
    if(flag==-1){
        res=1/res;
    }
    return res;
}
double myPow_3(double x,int n){
    double res=0;
    if(abs(x)<1e-32){
        res=0;
    }
    else{
        if(n==0){
            res=1;
        }
        else if(n>0){
            int k=0;
            vector<int> tempK={1};
            vector<double> tempRes={x};
            for(int i=2;i<=n;i++){
                k++;
                tempK.push_back(i);
                tempRes.push_back(tempRes[k-1]*tempRes[k-1]);
            }
        }
        else {

        }
    }
    return res;
}
double myPow_4(double x, int n) {// this is right
        double res=0;
        if(n==0){
            return 1;
        }
        else if(n==-1){
            return 1/x;
        }
        else if(n==1){
            return x;
        }
        double temp=myPow_4(x,int(n/2));
        res=temp*temp;
        if(n%2==1){
                res*=x;
        }
        else if(n%2==-1){
            res/=x;
        }
        return res;
}
