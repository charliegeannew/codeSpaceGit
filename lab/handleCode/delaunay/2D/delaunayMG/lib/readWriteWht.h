/*************************************************************************
* File Name: whtHandleFile.h
* Creat Time: 2021年04月23日 星期五 13时01分04秒
* Author :Charliegean
* Mail :wht905@gmail.com
*************************************************************************/
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<std::vector<std::string>> getPLYHeader(std::vector<std::vector<std::string>>vec);

std::vector<int> getPLYPointFaceNum(std::vector<std::vector<std::string>>head);

std::vector<std::vector<double>> getPLYPointList(std::vector<std::vector<std::string>> vec);

std::vector<std::vector<int>> getPLYFaceList(std::vector<std::vector<std::string>> vec);

std::vector<std::vector<std::string>>setPLYHeader(std::vector<std::vector<std::string>>head,std::vector<int>pointFaceNum);

void whtWriteNodePLYFile(struct node *tNode,std::string writeFileName);
