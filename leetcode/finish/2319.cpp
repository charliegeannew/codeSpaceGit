/*************************************************************************
* File Name: 2319.cpp
* Creat Time: 2021年09月24日 星期五 12时35分05秒
* Author :Charliegean
* Mail :wht905@gmail.com
*************************************************************************/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

string validTicTacToe(vector<string>&board);
int main(int argc,char ** argv)
{
    cout << "Hello world" << endl;
    /* vector<string> board={"O X"," XO","X O"}; */
    vector<string> board={"                             ","                     O       ","         X           X       ","                             ","                             ","                             ","                             ","                             ","                             ","                             ","                             ","                             ","                             ","                             ","                             ","                             ","                      O      ","                             ","                             ","                             ","                             ","                             ","                             ","      X                      ","                             ","                             ","      O                      ","                             ","                             "};
    cout<<"the board is "<<endl;
    for(int i=0;i<board.size();i++){
        cout<<board[i]<<endl;
    }
    string flag=validTicTacToe(board);
    cout<<"flag is "<<flag<<endl;
    return 0;
}
string validTicTacToe(vector<string>&board){
    string res;
    int spaceNum=0;
    int N=board.size();
    int lineNum=0;
    bool divFlag=true,hanFlag=true;
    /* cout<<"N === "<<N<<endl; */
    if(N==1){
        /* cout<<"11111111111111"<<endl; */
        if(board[0][0]==' '){
            res="Pending";
        }
        else{
            res=board[0][0];
        }
    }
    else{
        for(int i=0;i<N;i++){
            hanFlag=true;
            divFlag=true;
            for(int j=0;j<N;j++){
                    /* cout<<"b["<<i<<"]["<<j<<"] === "<<board[i][j]<<endl; */
                if(board[i][j]==' '){
                    spaceNum++;
                    hanFlag=false;
                }
                else{
                    if(board[i][0]!=board[i][j]){
                        hanFlag=false;
                    }
                }
                if(board[j][i]==' '){
                    spaceNum++;
                    divFlag=false;
                }
                else{
                    if(board[0][i]!=board[j][i]){
                        divFlag=false;
                    }
                }
            }
            if(hanFlag){
                res=board[i][0];
                lineNum++;
            }
            if(divFlag){
                res=board[0][i];
                lineNum++;
            }
            if(hanFlag |divFlag){
                break;
            }
        }
        /* cout<<"11111lineNum === "<<lineNum<<endl; */
        if(!hanFlag & !divFlag){
            /* cout<<"333333333333333"<<endl; */
            hanFlag=true;
            divFlag=true;
            for(int i=0;i<N;i++){
                if(board[i][i]==' '){
                    hanFlag=false;
                }
                else if(board[i][i]!=board[0][0]){
                    hanFlag=false;
                }   
                if(board[i][N-1-i]==' '){
                    divFlag=false;
                }
                else if(board[i][N-1-i]!=board[0][N-1] ){
                    divFlag=false;
                }   
            }
            if(hanFlag){
                res=board[0][0];
                lineNum++;
            }
            if(divFlag){
                /* cout<<"222222222222"<<endl; */
                res=board[0][N-1];
                lineNum++;
            }
        }
        /* cout<<"lineNum is "<<lineNum<<endl; */
        if(lineNum<=0){
            if(spaceNum==0){
                res="Draw";
            }
            else{
                res="Pending";
            }
        }
    }
    return res;
}
