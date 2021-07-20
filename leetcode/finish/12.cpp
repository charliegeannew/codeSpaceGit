/*************************************************************************
* File Name: 12.cpp
* Creat Time: 2021年04月17日 星期六 15时16分54秒
* Author :Charliegean
* Mail :wht905@gmail.com
*************************************************************************/
#include <iostream>
#include <stdlib.h>

using namespace std;

string intToRoman(int num);
int main()
{
    int *numList;
    int inputList[10]={3,4,9,49,58,59,1994};
    int sizeNum=7;
    numList=(int*)malloc(sizeof(int)*sizeNum);
    for(int i=0;i<sizeNum;i++){
        numList[i]=inputList[i];
    }
    for(int i=0;i<sizeNum;i++){
        int num=numList[i];
        cout<<"num === "<<num<<endl;
        cout<<"res === "<<intToRoman(num)<<endl;
    }
    return 0;
}
string intToRoman(int num){
    string res;
    int indexNum=0;
    if(num>=1000){
        indexNum=num/1000;
        res.append(indexNum,'M');
        num%=1000;
    }
    if(num>=500){
        if(num>=900){
            res+="CM";
            num-=900;
        }
        else{
            res+='D';
            num-=500;
        }
    }
    if(num>=100){
        if(num>=400){
            res+="CD";
            num-=400;
        }
        else{
            indexNum=num/100;
            res.append(indexNum,'C');
            num%=100;
        }
    }
    if(num>=50){
        if(num>=90){
            res+="XC";
            num-=90;
        }
        else{
            res+='L';
            num-=50;
        }
    }
    if(num>=10){
        if(num>=40){
            res+="XL";
            num-=40;
        }
        else{
            indexNum=num/10;
            res.append(indexNum,'X');
            num%=10;
        }
    }
    if(num>=5){
        if(num==9){
            res+="IX";
            num-=9;
        }
        else{
            res+='V';
            num-=5;
        }
    }
    if(num==4){
        res+="IV";
        num-=4;
    }
    else{
        res.append(num,'I');
    }
    return res;
}
