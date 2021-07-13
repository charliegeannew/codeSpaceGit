/*************************************************************************
* File Name: tempStringFunct.cpp
* Creat Time: 2021年05月13日 星期四 16时06分10秒
* Author :Charliegean
* Mail :wht905@gmail.com
*************************************************************************/
#include "tempStringFunct.h"

std::string changeVectorToString(std::vector<int> vec){
    std::string res;
    for(int i=0;i<vec.size();i++){
        res+=std::to_string(vec[i]);
        res+=' ';
    }
    return res;
}

std::string changeVectorToString(std::vector<std::vector<int>> vec){
    std::string res;
    for(int i=0;i<vec.size();i++){
        for(int j=0;j<vec[i].size();j++){
            res+=std::to_string(vec[i][j]);
            res+=' ';
        }
        res+='\n';
    }
    return res;
}
std::string changeVectorToString(std::vector<double> vec){
    std::string res;
    for(int i=0;i<vec.size();i++){
        res+=std::to_string(vec[i]);
        res+=' ';
    }
    return res;
}
std::string changeVectorToString(std::vector<std::vector<double>> vec){
    std::string res;
    for(int i=0;i<vec.size();i++){
        for(int j=0;j<vec[i].size();j++){
            res+=std::to_string(vec[i][j]);
            res+=' ';
        }
        res+='\n';
    }
    return res;
}
std::string changeVectorToString(std::vector<std::string> vec){
    std::string res;
    for(int i=0;i<vec.size();i++){
        res+=vec[i];
        res+=' ';
    }
    return res;
}

std::string changeVectorToString(std::vector<std::vector<std::string>> vec){
    std::string res;
    for(int i=0;i<vec.size();i++){
        for(int j=0;j<vec[i].size();j++){
            res+=vec[i][j];
            res+=' ';
        }
        res+='\n';
    }
    return res;
}
