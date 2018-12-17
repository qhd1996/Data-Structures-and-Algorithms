// Longest Palindromic Substring
// 动规，时间复杂度O(n^2)，空间复杂度O(n^2)
class Solution {
public:
	string longestPalindrome(const string& s) {
		const int n = s.size();
		bool f[n][n];
		fill_n(&f[0][0], n * n, false);
		// 用 vector 会超时
		//vector > f(n, vector(n, false));
		size_t max_len = 1, start = 0; // 最长回文子串的长度，起点
		for (size_t i = 0; i < s.size(); i++) {
			f[i][i] = true;
			for (size_t j = 0; j < i; j++) { // [j, i]
				f[j][i] = (s[j] == s[i] && (i - j < 2 || f[j + 1][i - 1]));
				if (f[j][i] && max_len < (i - j + 1)) {
					max_len = i - j + 1;
					start = j;
				}
			}
		}
		return s.substr(start, max_len);
	}
};

class Solution {
public:
    // Transform S into T.
    // For example, S = "abba", T = "^#a#b#b#a#$".
    // ^ and $ signs are sentinels appended to each end to avoid bounds checking
    string preProcess(string s) {
        int n = s.length();
    
        if (n == 0) return "^$";
    
        string ret = "^"; 
        for (int i = 0; i < n; i++)
            ret += "#" + s.substr(i, 1);    
        ret += "#$";
    
        return ret;
    }
 
// Longest Palindromic Substring
// Manacher's Algorithm，Time Complexity O(n), Space Complexity O(n)
    string longestPalindrome(string s) {
        string T = preProcess(s);
        int n = T.length();
        int *P = new int[n];
        int C = 0, R = 0;
        for (int i = 1; i < n-1; i++) {
            int i_mirror = 2*C-i; // equals to i' = C - (i-C)
    
            P[i] = (R > i) ? min(R-i, P[i_mirror]) : 0;
    
            // Attempt to expand palindrome centered at i
            while (T[i + 1 + P[i]] == T[i - 1 - P[i]])
                P[i]++;
 
            // If palindrome centered at i expand past R,
            // adjust center based on expanded palindrome.
            if (i + P[i] > R) {
                C = i;
                R = i + P[i];
            }
        }
 
        // Find the maximum element in P.
        int maxLen = 0;
        int centerIndex = 0;
        for (int i = 1; i < n-1; i++) {
            if (P[i] > maxLen) {
            maxLen = P[i];
            centerIndex = i;
            }
        }
        delete[] P;
  
        return s.substr((centerIndex - 1 - maxLen)/2, maxLen);
    }
};
