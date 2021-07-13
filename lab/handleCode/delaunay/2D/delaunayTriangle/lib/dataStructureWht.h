/*************************************************************************
* File Name: dataStructureWht.h
* Creat Time: 2021年05月13日 星期四 15时58分08秒
* Author :Charliegean
* Mail :wht905@gmail.com
*************************************************************************/
#pragma once
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <math.h>

#include "../libwht/constantData.h"
#include "./treeHandleWht.h"

struct face{
    std::vector<std::vector<double>> facePointList;
};
struct node{
    std::vector<face> faceList;
    std::vector<double> begPoint={0,0,0};
    std::vector<double> endPoint={0,0,0};
    int color=0;
    int initBegEndFlag=0;
    struct node *ruChild,*rdChild,*luChild,*ldChild;
};
class teTree{
public:
    teTree(){}
    ~teTree(){}
    
    void getRootNodeFromPLYPointFaceList(std::vector<std::vector<double>>pointList,std::vector<std::vector<int>>faceList);
    void calculChild(struct node *rootNode,int depth);
    double calculNodeSize(struct node * tNode);

    struct node root;
    int maxDepth=0;
};
