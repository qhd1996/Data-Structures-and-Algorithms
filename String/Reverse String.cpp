class Solution {
public:
    void reverseWords(string &s) {
        reverse(s.begin(),s.end());
        //记录新字符串尾的位置
        int storeIndex=0;
        for(int i=0;i<s.size();i++){
           if(s[i]!=' '){
               //去除开头的空格
               if(storeIndex!=0) s[storeIndex++]=' ';
               int j=i;
               while(j<s.size()&&s[j]!=' '){
                   s[storeIndex++]=s[j++];
               }
               //现在生成的单词是倒序的，要进行反转
               reverse(s.begin()+storeIndex-(j-i),s.begin()+storeIndex);
               i=j;
           }
        }
        //去除结尾的空格
        s.erase(s.begin() + storeIndex, s.end());
    }
};
