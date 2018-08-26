//方法1，好理解但是会超时
class Solution {
public:
    //Dynamic Programming
    //
    int minCut(string s) 
    {
        int n = s.size();
        if(n<=1) return 0;
        
        //dp[i][j] represents the string starting from i and ending at j
        //Eg : abcd dp[1][3] means bcd
        vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
        
        //It will form an upper triangle
        
        //Length l=1
        //For each string which has only 1 aphabet -> min cut is 0
        for(int i=0;i<n;i++)
            dp[i][i]=0;
        
        //Length l=2
        //For string of length 2 -> If both alphabets same then min cut is 0 else 1
        for(int i=0;i<n-1;i++)
            dp[i][i+1] = s[i]==s[i+1] ? 0 : 1;
        
        //Lenght 3 to n
        //Perfect method to move diagonally in matrix
        //similar approach in Longest palindrome substring problem
         for(int l = 3;l <= n;l++)
         {
            for(int i = 0;i <= n-l;i++)
            {
                int j = i+l-1;
                
                if(isPalindrome(s,i,j))
                    dp[i][j] = 0;
                else
                {
                    for(int k=i;k<j;k++)
                    {
                        int curr = 1 + dp[i][k] + dp[k+1][j]; //Making one cut and checking the other two parts
                        dp[i][j] = min(dp[i][j],curr);
                    }
                        
                }//else
               
            }//i
        }//l
        
        
        return dp[0][n-1];
    }
    
    
    bool isPalindrome(string s,int low,int high)
    {
        while(low < high)
          if(s[low++] != s[high--]) 
              return false;
        
       return true;
    } 
};

//方法2
/**
*Even case: Diameter = (i+j) - (i-j) = 2j, j = 0, 1, 2... the diameter here is even such as 0, 2,4... the for loop starts at j=0.
*Odd case: Diameter = (i+j) - (i-j+1) = 2j-1, j = 1, 2, 3... the diameter here is odd such as 1,3,5...the for loop starts at j=1.
**/
class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> cut(n+1, 0);  // number of cuts for the first k characters
        for (int i = 0; i <= n; i++) cut[i] = i-1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; i-j >= 0 && i+j < n && s[i-j]==s[i+j] ; j++) // odd length palindrome
                cut[i+j+1] = min(cut[i+j+1],1+cut[i-j]);

            for (int j = 1; i-j+1 >= 0 && i+j < n && s[i-j+1] == s[i+j]; j++) // even length palindrome
                cut[i+j+1] = min(cut[i+j+1],1+cut[i-j+1]);
        }
        return cut[n];
    }
};
