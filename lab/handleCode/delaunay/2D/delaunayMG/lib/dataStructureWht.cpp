/*************************************************************************
* File Name: dataStructureWht.cpp
* Creat Time: 2021年05月13日 星期四 15时57分54秒
* Author :Charliegean
* Mail :wht905@gmail.com
*************************************************************************/
#include "dataStructureWht.h"

void teTree::getRootNodeFromPLYPointFaceList(std::vector<std::vector<double>>pointList,std::vector<std::vector<int>>faceList){
    for(int i=0;i<faceList.size();i++){
        struct face tempFace;
        tempFace.facePointList.push_back(pointList[faceList[i][1]]);
        tempFace.facePointList.push_back(pointList[faceList[i][2]]);
        tempFace.facePointList.push_back(pointList[faceList[i][3]]);
        this->root.faceList.push_back(tempFace);
    }
    getNodeBegEndPoint(&this->root);

}
void teTree::calculChild(struct node *rootNode,int depth){
    std::cout<<"depth is "<<depth<<std::endl;
    if(depth>this->maxDepth){
        std::cout<<"the depth is up to maxdepth, program exit"<<std::endl;
    }
    else{
        if(calculNodeSize(rootNode)>threshod){
        /* if(1){ */
            if(rootNode->color==0){
                calculteTreeChildNode(rootNode);
                calculChild(rootNode->ruChild,depth+1);
                calculChild(rootNode->rdChild,depth+1);
                calculChild(rootNode->luChild,depth+1);
                calculChild(rootNode->ldChild,depth+1);
            }
            else{
                std::cout<<"the node is pure,but maye the size is not meet the requirement!"<<std::endl;
            }
        }
        else{
            std::cout<<"the node is the small size!"<<std::endl;
        }
    }
} 
double teTree::calculNodeSize(struct node * tNode){
    double res=fabs((double)(tNode->endPoint[0]-tNode->begPoint[0]))*fabs((double)(tNode->endPoint[1]-tNode->begPoint[1]));
    return res;
}
