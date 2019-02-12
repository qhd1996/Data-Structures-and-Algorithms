//Greedy Algorithm
//Time complex O(n)
//Space complex O(n)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        const int ASCII_MAX = 255;
        int last[ASCII_MAX]; //Record the last position the corresponding word 
        int start = 0; //Record the start position of substring
        
        fill(last, last + ASCII_MAX, -1);
        int max_len = 0;
        for(int i = 0; i < s.size(); i++){
            if(last[s[i]]>=start){
                max_len = max(i - start, max_len);
                start = last[s[i]] + 1;
            }
            last[s[i]] = i;
        }
        return max((int)s.size() - start, max_len);
    }
};
