class Solution {
public:
    bool isNumber(string s) {
        bool flag = regex_match(s, regex("(\\s*)[+-]?((\\.[0-9]+)|([0-9]+(\\.[0-9]*)?))(e[+-]?[0-9]+)?(\\s*)"));
        return flag;
    }
};
