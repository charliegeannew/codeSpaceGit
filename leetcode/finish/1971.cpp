/*************************************************************************
*File Name: 1971.cpp
*Author: Charliegean
*wht905@gmail.com
*Created Time: Sun Oct 23 18:13:59 2022
 ************************************************************************/
#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world" << endl;
    return 0;
}

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        bool res=false;
        if(source==destination){
            res=true;
            return res;
        }
        vector<vector<int>>arr(n);
        for(int i=0;i<edges.size();i++){
            arr[edges[i][0]].push_back(edges[i][1]);
            arr[edges[i][1]].push_back(edges[i][0]);
        }
        map<int,bool>dic={{source,true}};
        vector<int>bef={source};
        vector<int>nex={};
        while(true){
            nex.clear();
            bool newf=false;
            for(int i=0;i<bef.size();i++){
                for(int j=0;j<arr[bef[i]].size();j++){
                    if(dic.find(arr[bef[i]][j])==dic.end()){
                        nex.push_back(arr[bef[i]][j]);
                        dic.insert(pair<int,bool>(arr[bef[i]][j],true));
                        newf=true;
                    }
                }
            }
            bef.clear();
            if(nex.size()==0){
                break;
            }
            for(int n:nex){
                if(n==destination){
                    res=true;
                    break;
                }
                bef.push_back(n);
            }
        }
        return res;
    }
};
