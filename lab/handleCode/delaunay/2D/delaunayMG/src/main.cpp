/*************************************************************************
* File Name: main.cpp
* Creat Time: 2021年05月13日 星期四 15时55分44秒
* Author :Charliegean
* Mail :wht905@gmail.com
*************************************************************************/
#include <iostream>
#include <vector>
#include <string>
#include <math.h>

#include "../libwht/printFunct.h"
#include "../libwht/readWrite.h"
#include "../libwht/tempNumberFunct.h"
#include "../libwht/tempStringFunct.h"
#include "../libwht/tempVectorFunct.h"
#include "../libwht/constantData.h"
#include "../lib/dataStructureWht.h"
#include "../lib/treeHandleWht.h"
#include "../lib/readWriteWht.h"

using namespace std;

int main()
{
    cout<<"threshod is "<<threshod<<endl;
    string fileName="../data/square.ply";
    vector<vector<string>> readfile=whtReadFile(fileName);
    vector<vector<string>> headList=getPLYHeader(readfile);
    vector<vector<double>> pointList=getPLYPointList(readfile);
    vector<vector<int>> faceList=getPLYFaceList(readfile);
    vector<int> pointFaceNum=getPLYPointFaceNum(headList);
    whtPrintVector(pointFaceNum);
    whtPrintVector(pointList);
    whtPrintVector(faceList);
    
    teTree tree;
    tree.getRootNodeFromPLYPointFaceList(pointList,faceList);
    tree.maxDepth=1;
    tree.calculChild(&tree.root,1);
    whtPrintNode(*tree.root.ldChild);
    string writeFileName="../res/ldChild.ply";
    whtWriteNodePLYFile(tree.root.ldChild,writeFileName);
    return 0;
}

