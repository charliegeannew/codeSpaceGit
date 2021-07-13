/*************************************************************************
* File Name: tempStringFunct.h
* Creat Time: 2021年05月13日 星期四 16时06分00秒
* Author :Charliegean
* Mail :wht905@gmail.com
*************************************************************************/
#pragma once
#include <iostream>
#include <string>
#include <vector>

std::string changeVectorToString(std::vector<int> vec);

std::string changeVectorToString(std::vector<std::vector<int>> vec);

std::string changeVectorToString(std::vector<double> vec);

std::string changeVectorToString(std::vector<std::vector<double>> vec);

std::string changeVectorToString(std::vector<std::string> vec);

std::string changeVectorToString(std::vector<std::vector<std::string>> vec);
