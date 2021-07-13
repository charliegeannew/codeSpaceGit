/*************************************************************************
* File Name: treeHandleWht.h
* Creat Time: 2021年05月13日 星期四 20时12分40秒
* Author :Charliegean
* Mail :wht905@gmail.com
*************************************************************************/
#pragma once
#include "dataStructureWht.h"
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

void whtPrintNode(struct node tNode);
void setFaceBeginEndPoint(std::vector<double>begPoint,std::vector<double>endPoint);
void getNodeBegEndPoint(struct node *tNode);

void calculteTreeChildNode(struct node *rootNode);
/* void setNewNode(struct node *tNode); */
std::vector<std::vector<double>> getSqurePointList(std::vector<double> begPoint,std::vector<double> endPoint);
std::vector<double> calcalMidPoint(std::vector<double> begPoint,std::vector<double>endPoint);
std::vector<double> getDivideMidPoint(std::vector<double>fontPoint,std::vector<double>bePoint,double coord,int coordIndex);
int getDivideFlag(std::vector<std::vector<double>> facePointList,double coord,int coordIndex);
void setFace(struct face * tFace,std::vector<double> firPoint,std::vector<double> secPoint,std::vector<double> thirPoint);
void whtDivideNode(struct node *tNode,struct node *fontNode,struct node * beNode,std::vector<double> midPoint,int coordIndex);
double calPointLen(std::vector<double>begPoint,std::vector<double> endPoint);
double calTriArea(std::vector<double> pointA,std::vector<double>pointB,std::vector<double>pointC);

std::vector<std::vector<double>> getNodePointList(struct node *tNode);
std::vector<std::vector<int>> getNodeFaceList(struct node *tNode);
