class Solution {
public:
    string countAndSay(int n) {
        string s("1");
        
        while(--n){
            s=getNext(s);
        }
        
        return s;
    }
    
    string getNext(string s){
        string ss;
        int i=0;
        while(i<s.size()){
            char c=s[i];
            int count=0;
            for(;c==s[i]&&i<s.size();i++,count++){
            }
            ss+=(count-0+'0');
            ss+=c;
        }
        return ss;
    }
};
