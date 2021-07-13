/*************************************************************************
* File Name: whtHandleFile.cpp
* Creat Time: 2021年04月23日 星期五 22时29分44秒
* Author :Charliegean
* Mail :wht905@gmail.com
*************************************************************************/
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include "readWriteWht.h"
#include "treeHandleWht.h"
#include "../libwht/readWrite.h"
#include "../libwht/tempVectorFunct.h"
#include "../libwht/tempStringFunct.h"

std::vector<std::vector<std::string>> getPLYHeader(std::vector<std::vector<std::string>>vec){
    std::vector<std::vector<std::string>> res;
    for(int i=0;i<vec.size();i++){
        res.push_back(vec[i]);
        if(vec[i].size()>0&&vec[i][0]=="end_header"){
            break;
        }
    }
    return res;
}

std::vector<int> getPLYPointFaceNum(std::vector<std::vector<std::string>>head){
    std::vector<int> res={0,0};
    for(int i=0;i<head.size();i++){
        if(head[i].size()>=3){
            if(head[i][1]=="vertex"){
                res[0]=atoi(head[i][2].c_str());
            }
            else if(head[i][1]=="face"){
                res[1]=atoi(head[i][2].c_str());
            }
        }
    }
    return res;
}

std::vector<std::vector<double>> getPLYPointList(std::vector<std::vector<std::string>> vec){
    std::vector<std::vector<double>> res;
    int begLine=0,endLine=0,pointNum=-1;
    std::cout<<std::setprecision(10);
    for(int i=0;i<vec.size();i++){
        if(vec[i][0]=="end_header"){
            begLine=i+1;
            endLine=begLine+pointNum;
            break;
        }
        if(vec[i].size()>=3&&vec[i][1]=="vertex"&&pointNum<0){
            pointNum=atoi(vec[i][2].c_str());
        }
    }
    for(int i=begLine;i<endLine;i++){
        if(vec[i].size()!=3){
            std::cout<<"error vertex num error!"<<std::endl;
            break;
        }
        res.push_back({atof(vec[i][0].c_str()),atof(vec[i][1].c_str()),atof(vec[i][2].c_str())});
    }
    return res;
}

std::vector<std::vector<int>> getPLYFaceList(std::vector<std::vector<std::string>> vec){
    std::vector<std::vector<int>> res;
    int begLine=0,endLine=0,pointNum=-1,faceNum=-1;
    for(int i=0;i<vec.size();i++){
        if(vec[i][0]=="end_header"){
            begLine=i+1+pointNum;
            endLine=begLine+pointNum+faceNum;
            break;
        }
        if(vec[i].size()>=3&&vec[i][1]=="vertex"&&pointNum<0){
            pointNum=atoi(vec[i][2].c_str());
        }
        if(vec[i].size()>=3&&vec[i][1]=="face"&&faceNum<0){
            faceNum=atoi(vec[i][2].c_str());
        }
    }
    for(int i=begLine;i<endLine&&i<vec.size();i++){
        std::vector<int>temp;
        for(int j=0;j<vec[i].size();j++){
            temp.push_back(atoi(vec[i][j].c_str()));
        }
        res.push_back(temp);
    }
    return res;
}

std::vector<std::vector<std::string>>setPLYHeader(std::vector<std::vector<std::string>>head,std::vector<int> pointFaceNum){
    std::vector<std::vector<std::string>> res(head);
    for(int i=0;i<res.size();i++){
        if(res[i].size()>=3){
            if(res[i][1]=="vertex"){
                res[i][2]=std::to_string(pointFaceNum[0]);
            }
            else if(res[i][1]=="face"){
                res[i][2]=std::to_string(pointFaceNum[1]);
            }
        }
    }
    return res;
}
void whtWriteNodePLYFile(struct node *tNode,std::string writeFileName){
    std::string fileName="../data/head.ply";
    std::vector<std::vector<std::string>>plyHead=getPLYHeader(whtReadFile(fileName));
    std::vector<std::vector<double>>tempPointListRes=getNodePointList(tNode);
    std::vector<std::vector<int>>tempFaceListRes=getNodeFaceList(tNode);
    std::vector<int>pointFacNum={0,0};
    pointFacNum[0]=tempPointListRes.size();
    pointFacNum[1]=tempFaceListRes.size();
    whtWriteFile(writeFileName,changeVectorToString(setPLYHeader(plyHead,pointFacNum)),0);
    whtWriteFile(writeFileName,changeVectorToString(tempPointListRes),1);
    whtWriteFile(writeFileName,changeVectorToString(tempFaceListRes),1);
}
