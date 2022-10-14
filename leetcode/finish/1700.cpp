/*************************************************************************
*File Name: 1700.cpp
*Author: Charliegean
*wht905@gmail.com
*Created Time: Fri Oct 14 22:01:47 2022
 ************************************************************************/
#include <iostream>

using namespace std;
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int res=0;
        int sind=0,tind=0;
        bool flag=true;
        while(flag){
            flag=false;
            int i=tind;
            for(;i<students.size();i++){
                if(sandwiches[sind]==students[i]){
                    flag=true;
                    break;
                }
            }
            if(flag){
                sind++;
                students.erase(students.begin()+i);
            }
            else{
                i=0;
                for(;i<tind;i++){
                    if(sandwiches[sind]==students[i]){
                        flag=true;
                        break;
                    }
                }
                if(flag){
                    sind++;
                    students.erase(students.begin()+i);
                }
            }
        }
        res=students.size();
        return res;
    }
};

int main()
{
    cout << "Hello world" << endl;
    return 0;
}

