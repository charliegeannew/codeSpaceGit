class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int>charNum=this->getWordChar(licensePlate);
        
        //print(charNum);
        //*/
        string res;
        int now=0;
        for(int i=0;i<words.size();i++){
            int temp=this->getWord(words[i],charNum);
            if(temp>0){
                if(now==0 | now>temp){
                    res=words[i];
                    now=temp;
                }
            }
        }
        return res;
    }
    int getWord(string s,vector<int>charNum){
        int res=s.length();
        /*cout<<"s=== "<<s<<endl;
        for(int i=0;i<charNum.size();i++){
            cout<<charNum[i]<<'\t';
        }
        cout<<endl;
        //*/
        for(int i=0;i<s.length();i++){
            if(charNum[s[i]-'a']>=1){
                charNum[s[i]-'a']--;
                charNum[26]--;
            }
            /*else if (charNum[26]==0){
                break;
            }
            else{
                res=-1;
                break;
            }
            //*/
        }
        if(charNum[26]>0){
            res=-1;
        }
        return res;
    }
    vector<int>getWordChar(string s){
        vector<int>charNum(27,0);
        for(int i=0;i<s.length();i++){
            if(s[i]-'a'>=0 & s[i]-'z'<=0){
                charNum[s[i]-'a']++;
                charNum[26]++;
            }
            else if(s[i]-'A'>=0 & s[i]-'Z'<=0){
                charNum[s[i]-'A']++;
                charNum[26]++;
            }
        }
        return charNum;
    }
};