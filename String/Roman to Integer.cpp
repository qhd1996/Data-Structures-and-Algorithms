/**从前往后扫描，用一个临时变量记录分段数字。
*如果当前比前一个大，说明这一段的值应该是当前这个值减去上一个值。比如 IV = 5 – 1 ；否则，将当
*前值加入到结果中，然后开始下一段记录。比如 VI = 5 + 1, II=1+1
**/
class Solution {
public:
    int romanToInt(string s) {
        int result=0;
        for(int i=0;i<s.size();i++){
            if(i>0&&map(s[i])>map(s[i-1])){
                //为什么要乘2，因为没读到这里之前以为是正数多加了一次
                result+=(map(s[i])-2*map(s[i-1]));
            }else{
                result+=map(s[i]);
            }
        }
        return result;
    }

private:
    int map(const char c){
        switch(c){
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
        }
    }
};
