/*************************************************************************
* File Name: 794.cpp
* Creat Time: 2021年09月24日 星期五 10时35分28秒
* Author :Charliegean
* Mail :wht905@gmail.com
*************************************************************************/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool validTicTacToe(vector<string>&board);
int countLineNum(vector<string>&board);
char lineChar(vector<string>&board);
int main(int argc,char ** argv)
{
    cout << "Hello world" << endl;
    vector<string> board={"OOO","OOX","XO "};
    cout<<"the board is "<<endl;
    for(int i=0;i<board.size();i++){
        cout<<board[i]<<endl;
    }
    bool flag=validTicTacToe(board);
    cout<<"flag is "<<flag<<endl;
    return 0;
}
bool validTicTacToe(vector<string>&board){
    bool flag=true;
    /* this is test char numober */ 
    int xNum=0;
    int oNum=0;
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[i].length();j++){
            if(board[i][j]=='X'){
                xNum++;
            }
            if(board[i][j]=='O'){
                oNum++;
            }
        }
    }

    if(oNum>0 & xNum==0){
        flag=false;
    }
    /* if(abs(xNum-oNum)>1){ */
    /*     flag=false; */
    /* } */
    if((xNum-oNum)>1 || xNum-oNum<0){
        flag=false;
    }


    /* this is test any line for 3 */
    int lineNum=0;
    
    /* for(int i=0;i<board.size();i++){ */
    /*     if(board[i][0]==board[i][1] && board[i][1]==board[i][2] && board[i][0] != ' '){ */
    /*         lineNum++; */
    /*     } */
    /* } */
    /* for(int i=0;i<board[0].length();i++){ */
    /*     if(board[0][i]==board[1][i] && board[1][i]==board[2][i] && board[0][i]!=' '){ */
    /*         lineNum++; */
    /*     } */
    /* } */
    /* if(board[0][0]==board[1][1] && board[1][1]==board[2][2] && board[0][0]!=' '){ */
    /*     lineNum++; */
    /* } */
    /* if(board[0][2]==board[1][1] && board[1][1]==board[2][0]&& board[1][1]!=' '){ */
    /*     lineNum++; */
    /* } */
    lineNum=countLineNum(board);

    /* cout<<"line is "<<lineNum<<endl; */
    if(lineNum>1 && flag){
        /* flag=false; */
        bool tempFlag=false;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].length();j++){
                char temp;
                if(board[i][j]!=' '){
                    temp=board[i][j];
                    board[i][j]=' ';
                    if(countLineNum(board)==0){
                        tempFlag=true;
                    }
                    board[i][j]=temp;
                }
                if(tempFlag){
                    break;
                }
            }
            if(tempFlag){
                break;
            }
        }
        flag=tempFlag;
    }
    if(lineNum>0 & flag){
        cout<<"11111111"<<endl;
        if(lineChar(board)=='X'){
        cout<<"2222222222"<<endl;
            if(xNum==oNum){
        cout<<"3333333333"<<endl;
                flag=false;
            }
        }
        else{
        cout<<"i000000000"<<endl;
            if(xNum>oNum){
        cout<<"4444444444444"<<endl;
                flag=false;
            }
        }

    }
    return  flag;
}
char lineChar(vector<string>&board){
    char res=' ';
    for(int i=0;i<board.size();i++){
        if(board[i][0]==board[i][1] && board[i][1]==board[i][2] && board[i][0] != ' '){
            res=board[i][0];
        }
    }
    for(int i=0;i<board[0].length();i++){
        if(board[0][i]==board[1][i] && board[1][i]==board[2][i] && board[0][i]!=' '){
            res=board[0][i];
        }
    }
    if(board[0][0]==board[1][1] && board[1][1]==board[2][2] && board[0][0]!=' '){
        res=board[0][0];
    }
    if(board[0][2]==board[1][1] && board[1][1]==board[2][0]&& board[1][1]!=' '){
        res=board[1][1];
    }
    cout<<"res is "<<res<<endl;
    return res;
}
int countLineNum(vector<string>&board){
    int lineNum=0;
    for(int i=0;i<board.size();i++){
        if(board[i][0]==board[i][1] && board[i][1]==board[i][2] && board[i][0] != ' '){
            lineNum++;
        }
    }
    for(int i=0;i<board[0].length();i++){
        if(board[0][i]==board[1][i] && board[1][i]==board[2][i] && board[0][i]!=' '){
            lineNum++;
        }
    }
    if(board[0][0]==board[1][1] && board[1][1]==board[2][2] && board[0][0]!=' '){
        lineNum++;
    }
    if(board[0][2]==board[1][1] && board[1][1]==board[2][0]&& board[1][1]!=' '){
        lineNum++;
    }
    return lineNum;
}
