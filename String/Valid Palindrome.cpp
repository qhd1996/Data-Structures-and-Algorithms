/**
*大写转小写transform(str.begin(),str.end(),str.begin(),::tolower);
*小写转大写transform(str.begin(),str.end(),str.begin(),::toupper);
*isalnum()是否是字母或数字，isalpha()是否是字母，isdigit()是否是数字
**/
class Solution {
public:
    bool isPalindrome(string s) {
        for(int i=0,j=s.size()-1;i<j;i++,j--){
            while(isalnum(s[i])==false&&i<j) i++;
            while(isalnum(s[j])==false&&i<j) j--;
            if(toupper(s[i])!=toupper(s[j])) return false;
        }
        return true;
    }
};
