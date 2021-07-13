/*************************************************************************
* File Name: tempVectorFunct.cpp
* Creat Time: 2021年05月13日 星期四 16时05分29秒
* Author :Charliegean
* Mail :wht905@gmail.com
*************************************************************************/
#include "tempVectorFunct.h"

void whtPrintVector(std::vector<int> vec){
    if(vec.size()<1){
        std::cout<<"this vec is null!"<<std::endl;
    }
    else{
        std::cout<<"this is a int vector!"<<std::endl;
        for(int i=0;i<vec.size();i++){
            std::cout<<vec[i]<<' ';
        }
        std::cout<<std::endl;
    }
}
void whtPrintVector(std::vector<double> vec){
    if(vec.size()<1){
        std::cout<<"this vec is null!"<<std::endl;
    }
    else{
        std::cout<<"this is a double vector!"<<std::endl;
        for(int i=0;i<vec.size();i++){
            std::cout<<vec[i]<<' ';
        }
        std::cout<<std::endl;
    }
}
void whtPrintVector(std::vector<std::string> vec){
    if(vec.size()<1){
        std::cout<<"this vec is null!"<<std::endl;
    }
    else{
        std::cout<<"this is a string vector!"<<std::endl;
        for(int i=0;i<vec.size();i++){
            std::cout<<vec[i]<<' ';
        }
        std::cout<<std::endl;
    }
}

void whtPrintVector(std::vector<std::vector<int>> vec){
    if(vec.size()<1){
        std::cout<<"this vec is null!"<<std::endl;
    }
    else{
        std::cout<<"this is a int vector!"<<std::endl;
        for(int i=0;i<vec.size();i++){
            for(int j=0;j<vec[i].size();j++){
                std::cout<<vec[i][j]<<' ';
            }
            std::cout<<std::endl;
        }
        std::cout<<std::endl;
    }
}
void whtPrintVector(std::vector<std::vector<double>> vec){
    if(vec.size()<1){
        std::cout<<"this vec is null!"<<std::endl;
    }
    else{
        std::cout<<"this is a double vector!"<<std::endl;
        for(int i=0;i<vec.size();i++){
            for(int j=0;j<vec[i].size();j++){
                std::cout<<vec[i][j]<<' ';
            }
            std::cout<<std::endl;
        }
        std::cout<<std::endl;
    }
}
void whtPrintVector(std::vector<std::vector<std::string>> vec){
    if(vec.size()<1){
        std::cout<<"this vec is null!"<<std::endl;
    }
    else{
        std::cout<<"this is a string vector!"<<std::endl;
        for(int i=0;i<vec.size();i++){
            for(int j=0;j<vec[i].size();j++){
                std::cout<<vec[i][j]<<' ';
            }
            std::cout<<std::endl;
        }
        std::cout<<std::endl;
    }
}
bool whtVectorCompare(std::vector<int>sourceVec,std::vector<int>aimVec){
    bool flag=true;
    if(sourceVec.size()!=aimVec.size()){
        flag=false;
    }
    else{
        for(int i=0;i<sourceVec.size();i++){
            if(sourceVec[i]!=aimVec[i]){
                flag=false;
                break;
            }
        }
    }
    return flag;
}
bool whtVectorCompare(std::vector<double>sourceVec,std::vector<double>aimVec){
    bool flag=true;
    if(sourceVec.size()!=aimVec.size()){
        flag=false;
    }
    else{
        for(int i=0;i<sourceVec.size();i++){
            if(fabs(sourceVec[i]-aimVec[i])>threshod){
                flag=false;
                break;
            }
        }
    }
    return flag;
}
bool whtVectorCompare(std::vector<std::string>sourceVec,std::vector<std::string>aimVec){
    bool flag=true;
    if(sourceVec.size()!=aimVec.size()){
        flag=false;
    }
    else{
        for(int i=0;i<sourceVec.size();i++){
            if(sourceVec[i]!=aimVec[i]){
                flag=false;
                break;
            }
        }
    }
    return flag;
}

bool whtVectorCompare(std::vector<std::vector<int>>sourceVec,std::vector<std::vector<int>>aimVec){
    bool flag=true;
    if(sourceVec.size()!=aimVec.size()){
        flag=false;
    }
    else{
        for(int i=0;i<sourceVec.size();i++){
            if(!whtVectorCompare(sourceVec[i],aimVec[i])){
                flag=false;
                break;
            }
        }
    }
    return flag;
}
bool whtVectorCompare(std::vector<std::vector<double>>sourceVec,std::vector<std::vector<double>>aimVec){
    bool flag=true;
    if(sourceVec.size()!=aimVec.size()){
        flag=false;
    }
    else{
        for(int i=0;i<sourceVec.size();i++){
            if(!whtVectorCompare(sourceVec[i],aimVec[i])){
                flag=false;
                break;
            }
        }
    }
    return flag;
}
bool whtVectorCompare(std::vector<std::vector<std::string>>sourceVec,std::vector<std::vector<std::string>>aimVec){
    bool flag=true;
    if(sourceVec.size()!=aimVec.size()){
        flag=false;
    }
    else{
        for(int i=0;i<sourceVec.size();i++){
            if(!whtVectorCompare(sourceVec[i],aimVec[i])){
                flag=false;
                break;
            }
        }
    }
    return flag;
}

