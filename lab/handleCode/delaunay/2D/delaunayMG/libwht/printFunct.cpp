/*************************************************************************
* File Name: printFunctWht.cpp
* Creat Time: 2021年05月13日 星期四 15时56分33秒
* Author :Charliegean
* Mail :wht905@gmail.com
*************************************************************************/
#include "printFunct.h"

void whtPrintStar(std::string str){
    for(int i=0;i<(int)(75/str.length())+1;i++){
        std::cout<<str;
    }
    std::cout<<std::endl;
}
