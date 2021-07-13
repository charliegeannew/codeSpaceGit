/*************************************************************************
* File Name: tempVectorFunct.h
* Creat Time: 2021年05月13日 星期四 16时05分20秒
* Author :Charliegean
* Mail :wht905@gmail.com
*************************************************************************/
#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include "constantData.h"

void whtPrintVector(std::vector<int> vec);
void whtPrintVector(std::vector<double> vec);
void whtPrintVector(std::vector<std::string> vec);

void whtPrintVector(std::vector<std::vector<int>> vec);
void whtPrintVector(std::vector<std::vector<double>> vec);
void whtPrintVector(std::vector<std::vector<std::string>> vec);

bool whtVectorCompare(std::vector<int>sourceVec,std::vector<int>aimVec);
bool whtVectorCompare(std::vector<double>sourceVec,std::vector<double>aimVec);
bool whtVectorCompare(std::vector<std::string>sourceVec,std::vector<std::string>aimVec);

bool whtVectorCompare(std::vector<std::vector<int>>sourceVec,std::vector<std::vector<int>>aimVec);
bool whtVectorCompare(std::vector<std::vector<double>>sourceVec,std::vector<std::vector<double>>aimVec);
bool whtVectorCompare(std::vector<std::vector<std::string>>sourceVec,std::vector<std::vector<std::string>>aimVec);
