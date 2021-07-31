/*************************************************************************
* File Name: 43.cpp
* Creat Time: 2021年07月28日 星期三 23时40分13秒
* Author :Charliegean
* Mail :wht905@gmail.com
*************************************************************************/
#include <iostream>
#include <string>

using namespace std;

string multiply(string num1,string num2);
int main(int argc,char ** argv)
{
    cout << "Hello world" << endl;
    string num1="9999",num2="999";
    cout<<"num1,num2 is "<<endl;
    cout<<num1<<','<<num2<<endl;
    string res;
    res=multiply(num1,num2);
    cout<<"res is "<<endl<<res<<endl;
    return 0;
}
string multiply(string num1,string num2){
    string res;
    int len1=num1.length();
    int len2=num2.length();
    int len=res.length();
    if(len1==1 & num1[0]=='0'){
        res="0";
    }
    else if(len2==1 & num2[0]=='0'){
        res="0";
    }
    else{
        int over=0;
        for(int i=len1-1;i>=0;i--){
            for(int j=len2-1;j>=0;j--){
                /* int index1=num1[i]-'0'; */
                /* int (num2[i]-'0')=num2[j]-'0'; */
                len=res.length();
                cout<<"(num1[i]-'0'),(num2[i]-'0')==="<<(num1[i]-'0')<<','<<(num2[i]-'0')<<endl;
                if(len-1<(len1-1-i)+(len2-1-j)){
                    cout<<"11111111111111111"<<endl;
                    int numI=((num1[i]-'0')*(num2[j]-'0')+over)%10;
                    over=(int)(((num1[i]-'0')*(num2[j]-'0')+over)/10);
                    res=to_string(numI)+res;
                }
                else{
                    cout<<"2222222222222222"<<endl;
                    int numI=((num1[i]-'0')*(num2[j]-'0')+over+(res[len-1-(len1-1-i+len2-1-j)]-'0'))%10;
                    over=(int)(((num1[i]-'0')*(num2[j]-'0')+over+(res[len-1-(len1-1-i+len2-1-j)]-'0'))/10);
                    res[len-1-(len1-1-i+len2-1-j)]=(char)(numI)+'0';
                }
                cout<<"res,len is "<<res<<','<<len<<endl;
            }
            if(over>0){
                if((len1-1-i+len2-1)<len-1){
                    res[len-1-(len1-1-i+len2-1)]=(char)(over)+'0';
                }
                else{
                    res=to_string(over)+res;
                }
            }
            over=0;
        }
    }
    return res;
}
