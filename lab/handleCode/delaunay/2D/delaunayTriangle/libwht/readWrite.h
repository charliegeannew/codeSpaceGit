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

std::vector<std::vector<std::string>> whtReadFile(std::string fileName);

void whtWriteFile(std::string fileName,std::string str,int flag);
