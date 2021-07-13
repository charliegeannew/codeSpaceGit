/*************************************************************************
* File Name: tempNumFunct.cpp
* Creat Time: 2021年05月13日 星期四 16时06分38秒
* Author :Charliegean
* Mail :wht905@gmail.com
*************************************************************************/
#include "tempNumberFunct.h"
std:: vector<int> changeStringToInt(std::vector<std::string>&vec){
    std::vector<int> res;
    for(int i=0;i<vec.size();i++){
        res.push_back(std::atoi(vec[i].c_str()));
    }
    return res;
}

std:: vector<double> changeStringToDouble(std::vector<std::string>&vec){
    std::vector<double> res;
    for(int i=0;i<vec.size();i++){
        res.push_back(std::atof(vec[i].c_str()));
    }
    return res;
}

