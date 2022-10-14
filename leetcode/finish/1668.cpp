/*************************************************************************
*File Name: 1668.cpp
*Author: Charliegean
*wht905@gmail.com
*Created Time: Fri Oct 14 17:47:11 2022
 ************************************************************************/
#include <iostream>

using namespace std;
class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int res=0;
        int temp=0;
        if(sequence==word){
            return 1;
        }
        else if(sequence.length()<word.length()){
            return 0;
        }
        for(int i=0;i<=sequence.length()-word.length();i++){
            int k=0;
            while(true){
                if(i+word.length()*(k+1)>sequence.length()){
                    break;
                }
                else if(sequence.substr(i+word.length()*k,word.length())==word){
                    k++;
                    res=res>k?res:k;
                }
                else{
                    break;
                }
            } 
            //*/      
        }
        return res;
    }
};

int main()
{
    cout << "Hello world" << endl;
    return 0;
}

