/*************************************************************************
* File Name: /home/charliegean/codeSpace/lab/parallelCalculTree/lib/treeHandleWht.cpp
* Creat Time: 2021年05月13日 星期四 20时12分47秒
* Author :Charliegean
* Mail :wht905@gmail.com
*************************************************************************/
#include "treeHandleWht.h"
#include "dataStructureWht.h"

void whtPrintNode(struct node tNode){
    std::cout<<"in this octree the tNode is "<<tNode.color<<" the detail is :"<<std::endl;
    std::cout<<"begPoint is "<<tNode.begPoint[0]<<','<<tNode.begPoint[1]<<','<<tNode.begPoint[2]<<std::endl;
    std::cout<<"endPoint is "<<tNode.endPoint[0]<<','<<tNode.endPoint[1]<<','<<tNode.endPoint[2]<<std::endl;
    std::cout<<"the faceList is "<<std::endl;
    for(int i=0;i<tNode.faceList.size();i++){
        std::cout<<"this is the "<<i<<"th face!"<<std::endl;
        for(int j=0;j<tNode.faceList[i].facePointList.size();j++){
            for(int k=0;k<tNode.faceList[i].facePointList[j].size();k++){
                std::cout<<tNode.faceList[i].facePointList[j][k]<<' ';
            }
            std::cout<<std::endl;
        }
        std::cout<<std::endl;
    } 
}
void setFaceBeginEndPoint(struct face tFace,std::vector<double>&begPoint,std::vector<double>&endPoint){
    if(tFace.facePointList.size()!=3){
        std::cout<<"error this face do not has three point !"<<std::endl;
    }
    else{
        for(int i=0;i<tFace.facePointList.size();i++){
            for(int j=0;j<tFace.facePointList[i].size();j++){
                if(begPoint[j]>tFace.facePointList[i][j]){
                    begPoint[j]=tFace.facePointList[i][j];
                }
                if(endPoint[j]<tFace.facePointList[i][j]){
                    endPoint[j]=tFace.facePointList[i][j];
                }
            }
        }
    }
}
void getNodeBegEndPoint(struct node *tNode){
    if(tNode->faceList.size()>=1){
        if(tNode->initBegEndFlag==0){
            tNode->begPoint.assign(tNode->faceList[0].facePointList[0].begin(),tNode->faceList[0].facePointList[0].end());
            tNode->endPoint.assign(tNode->faceList[0].facePointList[0].begin(),tNode->faceList[0].facePointList[0].end());
        }
        for(int i=0;i<tNode->faceList.size();i++){
            setFaceBeginEndPoint(tNode->faceList[i],tNode->begPoint,tNode->endPoint);
        }
        tNode->initBegEndFlag=1;
    }
    else{
        std::cout<<"this node has no face and point!"<<std::endl;
    }
}
void calculteTreeChildNode(struct node *rootNode){
    std::vector<double> midPoint(calcalMidPoint(rootNode->begPoint,rootNode->endPoint));  
    std::vector<std::vector<double>> doCubePointList=getSqurePointList(rootNode->begPoint,midPoint);
    std::vector<std::vector<double>> upCubePointList=getSqurePointList(midPoint,rootNode->endPoint);
    /* std::cout<<"****************************"<<std::endl; */
    /* whtPrintVector(upCubePointList); */
    /* std::cout<<"****************************"<<std::endl; */
    rootNode->ldChild = new node();
    rootNode->ldChild->begPoint.assign(doCubePointList[0].begin(),doCubePointList[0].end());
    rootNode->ldChild->endPoint.assign(upCubePointList[0].begin(),upCubePointList[0].end());
    rootNode->luChild=new node();
    rootNode->luChild->begPoint.assign(doCubePointList[1].begin(),doCubePointList[1].end());
    rootNode->luChild->endPoint.assign(upCubePointList[1].begin(),upCubePointList[1].end());
    rootNode->rdChild=new node();
    rootNode->rdChild->begPoint.assign(doCubePointList[2].begin(),doCubePointList[2].end());
    rootNode->rdChild->endPoint.assign(upCubePointList[2].begin(),upCubePointList[2].end());
    rootNode->ruChild=new node();
    rootNode->ruChild->begPoint.assign(doCubePointList[3].begin(),doCubePointList[3].end());
    rootNode->ruChild->endPoint.assign(upCubePointList[3].begin(),upCubePointList[3].end());
    struct node *lNode=new node();
    struct node *rNode=new node();
    whtDivideNode(rootNode,rNode,lNode,midPoint,0);
    getNodeBegEndPoint(rNode);
    getNodeBegEndPoint(lNode);
    midPoint=calcalMidPoint(rNode->begPoint,rNode->endPoint);
    whtDivideNode(rNode,rootNode->ruChild,rootNode->rdChild,midPoint,1);
    midPoint=calcalMidPoint(lNode->begPoint,lNode->endPoint);
    whtDivideNode(lNode,rootNode->luChild,rootNode->ldChild,midPoint,1);
}
/* void setNewNode(struct node *tNode){ */
/* } */
std::vector<std::vector<double>> getSqurePointList(std::vector<double> begPoint,std::vector<double> endPoint){
    std::vector<std::vector<double>> resPointList;
    std::vector<double> tempLKH(endPoint);
    for(int i=0;i<endPoint.size();i++){
        tempLKH[i]=fabs(endPoint[i]-begPoint[i]);
    }
    resPointList.push_back(begPoint);
    begPoint[0]+=tempLKH[0];
    resPointList.push_back(begPoint);
    begPoint[0]-=tempLKH[0];
    begPoint[1]+=tempLKH[1];
    resPointList.push_back(begPoint);
    begPoint[0]+=tempLKH[0];
    resPointList.push_back(begPoint);

    return resPointList;
}
std::vector<double> calcalMidPoint(std::vector<double> begPoint,std::vector<double>endPoint){
    std::vector<double>res={(begPoint[0]+endPoint[0])/2,(begPoint[1]+endPoint[1])/2,(begPoint[2]+endPoint[2])/2};
    return res;
}
std::vector<double> getDivideMidPoint(std::vector<double>fontPoint,std::vector<double>bePoint,double coord,int coordIndex){
    std::vector<double> res={0,0,0};
    if(fabs(fontPoint[coordIndex]-bePoint[coordIndex])<threshod){
        if(fabs(fontPoint[coordIndex]-coord)<threshod){
            if(fabs(fontPoint[0]-bePoint[0])<threshod & fabs(fontPoint[1]-bePoint[1])<threshod){
                res.assign(fontPoint.begin(),fontPoint.end());
                res[coordIndex]=coord;
            }
            else{
                std::cout<<"error fontPoint != bePoint"<<std::endl;
            }
        }
        else{
            std::cout<<"error fontPoint and bePoint not in different egde!"<<std::endl;
        }
    }
    else{
        double temp=(fontPoint[coordIndex]-coord)/(fontPoint[coordIndex]-bePoint[coordIndex]);
        res[coordIndex]=coord;
        res[0]=fontPoint[0]-(fontPoint[0]-bePoint[0])*temp;
        res[1]=fontPoint[1]-(fontPoint[1]-bePoint[1])*temp;
        res[coordIndex]=coord;
    }
    return res;
}
int getDivideFlag(std::vector<std::vector<double>> facePointList,double coord,int coordIndex){
    int res=0,index=1;
    for(int i=0;i<facePointList.size();i++){
        if(fabs(facePointList[i][coordIndex]-coord)<threshod){
            res+=1*index;
        }
        else if(coord-facePointList[i][coordIndex]>0){
            res+=2*index;
        }
        index*=3;
    }
    return res;
}
void setFace(struct face * tFace,std::vector<double> firPoint,std::vector<double> secPoint,std::vector<double> thirPoint){
    if(tFace->facePointList.size()==0){
        tFace->facePointList.push_back(firPoint);
        tFace->facePointList.push_back(secPoint);
        tFace->facePointList.push_back(thirPoint);
    }
    else if(tFace->facePointList.size()==3){
        tFace->facePointList[0].assign(firPoint.begin(),firPoint.end());
        tFace->facePointList[1].assign(secPoint.begin(),secPoint.end());
        tFace->facePointList[2].assign(thirPoint.begin(),thirPoint.end());
    }
    else{
        std::cout<<"this face has wrong point number!"<<std::endl;
    }
}
void whtDivideNode(struct node *tNode,struct node *fontNode,struct node * beNode,std::vector<double> midPoint,int coordIndex){
    int flag=-1;
    for(int i=0;i<tNode->faceList.size();i++){
        flag=getDivideFlag(tNode->faceList[i].facePointList,midPoint[0],coordIndex);
        switch(flag){
        case 0:
        case 1:
        case 3:
        case 9:fontNode->faceList.push_back(tNode->faceList[i]);break;
        case 2:{
                face *faceFont1 =new face();
                face *faceFont2 =new face();
                face *faceBe =new face();
                face *faceMid =new face();
                std::vector<double> flPoint=getDivideMidPoint(tNode->faceList[i].facePointList[0],tNode->faceList[i].facePointList[1],midPoint[coordIndex],coordIndex);
                std::vector<double> frPoint=getDivideMidPoint(tNode->faceList[i].facePointList[0],tNode->faceList[i].facePointList[2],midPoint[coordIndex],coordIndex);
                setFace(faceFont1,tNode->faceList[i].facePointList[1],tNode->faceList[i].facePointList[2],flPoint);
                setFace(faceFont2,tNode->faceList[i].facePointList[2],flPoint,frPoint);
                setFace(faceBe,tNode->faceList[i].facePointList[0],flPoint,frPoint);
                setFace(faceMid,midPoint,flPoint,frPoint);
                        fontNode->faceList.push_back(*faceFont1);
                fontNode->faceList.push_back(*faceFont2);
                beNode->faceList.push_back(*faceBe);
                fontNode->faceList.push_back(*faceMid);
                beNode->faceList.push_back(*faceMid);
                break;
               }
        case 18:{
                face *faceFont1 =new face();
                face *faceFont2 =new face();
                face *faceBe =new face();
                face *faceMid =new face();
                std::vector<double> flPoint=getDivideMidPoint(tNode->faceList[i].facePointList[0],tNode->faceList[i].facePointList[2],midPoint[coordIndex],coordIndex);
                std::vector<double> frPoint=getDivideMidPoint(tNode->faceList[i].facePointList[1],tNode->faceList[i].facePointList[2],midPoint[coordIndex],coordIndex);
                setFace(faceFont1,tNode->faceList[i].facePointList[0],tNode->faceList[i].facePointList[1],flPoint);
                setFace(faceFont2,tNode->faceList[i].facePointList[1],flPoint,frPoint);
                setFace(faceBe,tNode->faceList[i].facePointList[2],flPoint,frPoint);
                setFace(faceMid,midPoint,flPoint,frPoint);

                fontNode->faceList.push_back(*faceFont1);
                fontNode->faceList.push_back(*faceFont2);
                beNode->faceList.push_back(*faceBe);
                fontNode->faceList.push_back(*faceMid);
                beNode->faceList.push_back(*faceMid);
                break;
                }
        case 6:{
                face *faceFont1 =new face();
                face *faceFont2 =new face();
                face *faceBe =new face();
                face *faceMid =new face();
                std::vector<double> flPoint=getDivideMidPoint(tNode->faceList[i].facePointList[0],tNode->faceList[i].facePointList[1],midPoint[coordIndex],coordIndex);
                std::vector<double> frPoint=getDivideMidPoint(tNode->faceList[i].facePointList[1],tNode->faceList[i].facePointList[2],midPoint[coordIndex],coordIndex);
                setFace(faceFont1,tNode->faceList[i].facePointList[0],tNode->faceList[i].facePointList[2],flPoint);
                setFace(faceFont2,tNode->faceList[i].facePointList[2],flPoint,frPoint);
                setFace(faceBe,tNode->faceList[i].facePointList[1],flPoint,frPoint);
                setFace(faceMid,midPoint,flPoint,frPoint);

                fontNode->faceList.push_back(*faceFont1);
                fontNode->faceList.push_back(*faceFont2);
                beNode->faceList.push_back(*faceBe);
                fontNode->faceList.push_back(*faceMid);
                beNode->faceList.push_back(*faceMid);
                 break;
                }
        case 8:{
                face *faceBe1 =new face();    
                face *faceBe2 =new face();    
                face *faceFont =new face();    
                face *faceMid =new face();    
                std::vector<double> blPoint=getDivideMidPoint(tNode->faceList[i].facePointList[0],tNode->faceList[i].facePointList[2],midPoint[coordIndex],coordIndex);
                std::vector<double> brPoint=getDivideMidPoint(tNode->faceList[i].facePointList[1],tNode->faceList[i].facePointList[2],midPoint[coordIndex],coordIndex);
                setFace(faceBe1,tNode->faceList[i].facePointList[0],tNode->faceList[i].facePointList[1],blPoint);
                setFace(faceBe2,tNode->faceList[i].facePointList[1],blPoint,brPoint);
                setFace(faceFont,tNode->faceList[i].facePointList[2],blPoint,brPoint);
                setFace(faceMid,midPoint,blPoint,brPoint);

                fontNode->faceList.push_back(*faceFont);
                fontNode->faceList.push_back(*faceMid);
                beNode->faceList.push_back(*faceBe1);
                beNode->faceList.push_back(*faceBe2);
                beNode->faceList.push_back(*faceMid);
                break;
               }
        case 20:{
                face *faceBe1 =new face();    
                face *faceBe2 =new face();    
                face *faceFont =new face();    
                face *faceMid =new face();    
                std::vector<double> blPoint=getDivideMidPoint(tNode->faceList[i].facePointList[0],tNode->faceList[i].facePointList[1],midPoint[coordIndex],coordIndex);
                std::vector<double> brPoint=getDivideMidPoint(tNode->faceList[i].facePointList[1],tNode->faceList[i].facePointList[2],midPoint[coordIndex],coordIndex);
                setFace(faceBe1,tNode->faceList[i].facePointList[0],tNode->faceList[i].facePointList[2],blPoint);
                setFace(faceBe2,tNode->faceList[i].facePointList[2],blPoint,brPoint);
                setFace(faceFont,tNode->faceList[i].facePointList[1],blPoint,brPoint);
                setFace(faceMid,midPoint,blPoint,brPoint);

                fontNode->faceList.push_back(*faceFont);
                fontNode->faceList.push_back(*faceMid);
                beNode->faceList.push_back(*faceBe1);
                beNode->faceList.push_back(*faceBe2);
                beNode->faceList.push_back(*faceMid);
                break;
                }
        case 24:{
                face *faceBe1 =new face();
                face *faceBe2 =new face();
                face *faceFont =new face();
                face *faceMid =new face();
                std::vector<double> blPoint=getDivideMidPoint(tNode->faceList[i].facePointList[0],tNode->faceList[i].facePointList[1],midPoint[coordIndex],coordIndex);
                std::vector<double> brPoint=getDivideMidPoint(tNode->faceList[i].facePointList[0],tNode->faceList[i].facePointList[2],midPoint[coordIndex],coordIndex);
                setFace(faceBe1,tNode->faceList[i].facePointList[1],tNode->faceList[i].facePointList[2],blPoint);
                setFace(faceBe2,tNode->faceList[i].facePointList[2],blPoint,brPoint);
                setFace(faceFont,tNode->faceList[i].facePointList[0],blPoint,brPoint);
                setFace(faceMid,midPoint,blPoint,brPoint);

                fontNode->faceList.push_back(*faceFont);
                fontNode->faceList.push_back(*faceMid);
                beNode->faceList.push_back(*faceBe1);
                beNode->faceList.push_back(*faceBe2);
                beNode->faceList.push_back(*faceMid);
                break;
                }
        case 17:
        case 23:
        case 25:
        case 26:beNode->faceList.push_back(tNode->faceList[i]);break;
        case 4:{
                face *faceMid=new face();
                setFace(faceMid,tNode->faceList[i].facePointList[0],tNode->faceList[i].facePointList[1],midPoint);

                fontNode->faceList.push_back(tNode->faceList[i]);
                fontNode->faceList.push_back(*faceMid);
                beNode->faceList.push_back(*faceMid);
                 break;
               }
        case 10:{
                face *faceMid=new face();
                setFace(faceMid,tNode->faceList[i].facePointList[0],tNode->faceList[i].facePointList[2],midPoint);

                fontNode->faceList.push_back(tNode->faceList[i]);
                fontNode->faceList.push_back(*faceMid);
                beNode->faceList.push_back(*faceMid);
                break;
                }
        case 12:{
                face *faceMid=new face();
                setFace(faceMid,tNode->faceList[i].facePointList[1],tNode->faceList[i].facePointList[2],midPoint);

                fontNode->faceList.push_back(tNode->faceList[i]);
                fontNode->faceList.push_back(*faceMid);
                beNode->faceList.push_back(*faceMid);
                break;
                }
        case 14:{
                face *faceMid=new face();
                setFace(faceMid,tNode->faceList[i].facePointList[1],tNode->faceList[i].facePointList[2],midPoint);
                beNode->faceList.push_back(tNode->faceList[i]);
                beNode->faceList.push_back(*faceMid);
                fontNode->faceList.push_back(*faceMid);
                break;
                }
        case 16:{
                face *faceMid=new face();
                setFace(faceMid,tNode->faceList[i].facePointList[0],tNode->faceList[i].facePointList[2],midPoint);

                beNode->faceList.push_back(tNode->faceList[i]);
                beNode->faceList.push_back(*faceMid);
                fontNode->faceList.push_back(*faceMid);
                break;
                }
        case 22:{
                face *faceMid=new face();
                setFace(faceMid,tNode->faceList[i].facePointList[0],tNode->faceList[i].facePointList[1],midPoint);

                beNode->faceList.push_back(tNode->faceList[i]);
                beNode->faceList.push_back(*faceMid);
                fontNode->faceList.push_back(*faceMid);
                break;
                }

        case 5:{
                face *faceFont=new face();
                face *faceBe  =new face();
                face *faceMid =new face();
                std::vector<double> midLinePoint=getDivideMidPoint(tNode->faceList[i].facePointList[0],tNode->faceList[i].facePointList[2],midPoint[coordIndex],coordIndex);
                if(calPointLen(midLinePoint,tNode->faceList[i].facePointList[1])>threshod){
                    setFace(faceFont,tNode->faceList[i].facePointList[1],tNode->faceList[i].facePointList[2],midLinePoint);
                    setFace(faceBe,tNode->faceList[i].facePointList[0],tNode->faceList[i].facePointList[1],midLinePoint);
                    setFace(faceMid,tNode->faceList[i].facePointList[1],midLinePoint,midPoint);

                    fontNode->faceList.push_back(*faceFont);
                    fontNode->faceList.push_back(*faceMid);
                    beNode->faceList.push_back(*faceBe);
                    beNode->faceList.push_back(*faceMid);
                }
                 break;
               }
        case 7:{
                face *faceFont=new face();
                face *faceBe  =new face();
                face *faceMid =new face();
                std::vector<double> midLinePoint=getDivideMidPoint(tNode->faceList[i].facePointList[1],tNode->faceList[i].facePointList[2],midPoint[coordIndex],coordIndex);
                if(calPointLen(midLinePoint,tNode->faceList[i].facePointList[0])>threshod){
                setFace(faceFont,tNode->faceList[i].facePointList[0],tNode->faceList[i].facePointList[2],midLinePoint);
                setFace(faceBe,tNode->faceList[i].facePointList[0],tNode->faceList[i].facePointList[1],midLinePoint);
                setFace(faceMid,tNode->faceList[i].facePointList[0],midLinePoint,midPoint);

                fontNode->faceList.push_back(*faceFont);
                fontNode->faceList.push_back(*faceMid);
                beNode->faceList.push_back(*faceBe);
                beNode->faceList.push_back(*faceMid);

                }
                break;
               }
        case 11:{
                face *faceFont=new face();
                face *faceBe  =new face();
                face *faceMid =new face();
                  std::vector<double> midLinePoint=getDivideMidPoint(tNode->faceList[i].facePointList[0],tNode->faceList[i].facePointList[1],midPoint[coordIndex],coordIndex);
                if(calPointLen(midLinePoint,tNode->faceList[i].facePointList[2])>threshod){
                setFace(faceFont,tNode->faceList[i].facePointList[1],tNode->faceList[i].facePointList[2],midLinePoint);
                setFace(faceBe,tNode->faceList[i].facePointList[0],tNode->faceList[i].facePointList[2],midLinePoint);
                setFace(faceMid,tNode->faceList[i].facePointList[2],midLinePoint,midPoint);

                fontNode->faceList.push_back(*faceFont);
                fontNode->faceList.push_back(*faceMid);
                beNode->faceList.push_back(*faceBe);
                beNode->faceList.push_back(*faceMid);

                }
                break;

                }
        case 15:{
                face *faceFont=new face();
                face *faceBe  =new face();
                face *faceMid =new face();
                std::vector<double> midLinePoint=getDivideMidPoint(tNode->faceList[i].facePointList[0],tNode->faceList[i].facePointList[1],midPoint[coordIndex],coordIndex);
                if(calPointLen(midLinePoint,tNode->faceList[i].facePointList[2])>threshod){
                setFace(faceFont,tNode->faceList[i].facePointList[0],tNode->faceList[i].facePointList[2],midLinePoint);
                setFace(faceBe,tNode->faceList[i].facePointList[1],tNode->faceList[i].facePointList[2],midLinePoint);
                setFace(faceMid,tNode->faceList[i].facePointList[2],midLinePoint,midPoint);

                fontNode->faceList.push_back(*faceFont);
                fontNode->faceList.push_back(*faceMid);
                beNode->faceList.push_back(*faceBe);
                beNode->faceList.push_back(*faceMid);

                }
                break;

                }
                case 19:{
                face *faceFont=new face();
                face *faceBe  =new face();
                face *faceMid =new face();
                std::vector<double> midLinePoint=getDivideMidPoint(tNode->faceList[i].facePointList[1],tNode->faceList[i].facePointList[2],midPoint[coordIndex],coordIndex);
                if(calPointLen(midLinePoint,tNode->faceList[i].facePointList[0])>threshod){
                setFace(faceFont,tNode->faceList[i].facePointList[0],tNode->faceList[i].facePointList[1],midLinePoint);
                setFace(faceBe,tNode->faceList[i].facePointList[0],tNode->faceList[i].facePointList[2],midLinePoint);
                setFace(faceMid,tNode->faceList[i].facePointList[0],midLinePoint,midPoint);

                fontNode->faceList.push_back(*faceFont);
                fontNode->faceList.push_back(*faceMid);
                beNode->faceList.push_back(*faceBe);
                beNode->faceList.push_back(*faceMid);

                }
                break;

                }
        case 21:{
                face *faceFont=new face();
                face *faceBe  =new face();
                face *faceMid =new face();
                std::vector<double> midLinePoint=getDivideMidPoint(tNode->faceList[i].facePointList[0],tNode->faceList[i].facePointList[2],midPoint[coordIndex],coordIndex);
                if(calPointLen(midLinePoint,tNode->faceList[i].facePointList[1])>threshod){
                setFace(faceFont,tNode->faceList[i].facePointList[0],tNode->faceList[i].facePointList[1],midLinePoint);
                setFace(faceBe,tNode->faceList[i].facePointList[1],tNode->faceList[i].facePointList[2],midLinePoint);
                setFace(faceMid,tNode->faceList[i].facePointList[1],midLinePoint,midPoint);

                fontNode->faceList.push_back(*faceFont);
                fontNode->faceList.push_back(*faceMid);
                beNode->faceList.push_back(*faceBe);
                beNode->faceList.push_back(*faceMid);

                }
                break;

                }
        default:std::cout<<"error flag="<<flag<<" is error!"<<std::endl;
        }
    }
}
double calPointLen(std::vector<double>begPoint,std::vector<double> endPoint){
    double len=0;
    if(begPoint.size()==3 && endPoint.size()==3){
        for(int i=0;i<begPoint.size();i++){
            len+=(begPoint[i]-endPoint[i])*(begPoint[i]-endPoint[i]);
        }
    }
    else{
        std::cout<<"error: the point has wrong index"<<std::endl;
    }
    return sqrt(len);
}
double calTriArea(std::vector<double> pointA,std::vector<double>pointB,std::vector<double>pointC){
    double area=0;
    double tempA=calPointLen(pointA,pointB);
    double tempB=calPointLen(pointB,pointC);
    double tempC=calPointLen(pointC,pointA);
    double p=(tempA+tempB+tempC)/2;
    area=sqrt(p*(p-tempA)*(p-tempB)*(p-tempC));
    return area;
}
std::vector<std::vector<double>> getNodePointList(struct node *tNode){
    std::vector<std::vector<double>> pointList;
    if(tNode!=NULL){
        for(int i=0;i<tNode->faceList.size();i++){
            pointList.insert(pointList.end(),tNode->faceList[i].facePointList.begin(),tNode->faceList[i].facePointList.end());
        }
    }
    else{
        std::cout<<"error :the node is null !"<<std::endl;
    }
    return pointList;
}
std::vector<std::vector<int>> getNodeFaceList(struct node *tNode){
    std::vector<std::vector<int>> faceList;
    if(tNode!=NULL){
        std::vector<int> tempFace={3,0,0,0};
        for(int i=0;i<tNode->faceList.size();i++){
            tempFace[1]=i*3+0;
            tempFace[2]=i*3+1;
            tempFace[3]=i*3+2;
            faceList.push_back(tempFace);
        }
    }
    else{
        std::cout<<"error :the node is null !"<<std::endl;
    }
    return faceList;
}
