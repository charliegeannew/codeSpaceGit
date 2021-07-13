/*************************************************************************
* File Name: whtHandleFile.cpp
* Creat Time: 2021年04月23日 星期五 22时29分44秒
* Author :Charliegean
* Mail :wht905@gmail.com
*************************************************************************/
/* #ifndef _WHTHANDLEFILE_H_ */
/* #define _WHTHANDLEFILE_H_ */  
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include "readWrite.h"

std::vector<std::vector<std::string>> whtReadFile(std::string fileName){
    std::ifstream infile;
    infile.open(fileName,std::ios::in);
    std::string s;
    std::vector<std::vector<std::string>> res;
    if(!infile.is_open()){
        std::cout<<"open file "<<fileName<<" fail!"<<std::endl;
        return res;
    }
    while(getline(infile,s)){
        std::vector<std::string> tempLine;
        int pos1=0;
        for(pos1=0;pos1<s.length();pos1++){
            if(s[pos1]!=' '){
                break;
            }
        }
        for(;pos1<s.length();pos1++){
            int len=0;
            while(pos1+len<s.length()&&s[pos1+len]!=' '){
                len++;
            }
            tempLine.push_back(s.substr(pos1,len));
            pos1+=len;
        }
        res.push_back(tempLine);
    }
    return res;
}
void whtWriteFile(std::string fileName,std::string str,int flag){
    std::ofstream file;
    if(flag==0){//new file 
        file.open(fileName,std::ios::trunc);
    }
    else if(flag==1){// add file at tail 
        file.open(fileName,std::ios::app);
    }
    else if(flag==2){// std out
        file.open(fileName,std::ios::out);
    }
    else{
        std::cout<<"error: flag out of range!"<<std::endl;
    }
    file<<str;
    file.close();
}
/* #endif */
