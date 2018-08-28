/**
*if k >= n/2, we can have transactions any time, it can be solved by O(n).
*else, we can do it in DP.
*use dp[k][i+1] represents, The max profit of using [0,i] data and k transactions.
*So we have:
*dp[k][i+1] = max(dp[k-1][i+1], dp[k][i], max( dp[k-1][j] + prices[i] - prices[j] ))
*= max(dp[k-1][i+1], dp[k][i], prices[i] + max( dp[k-1][j] - prices[j] )) { 0 <= j < i }
**/
class Solution {
public:
    int maxProfit_all(vector<int> &prices) {
        int n = prices.size();
        int sum = 0;
        for(int i = 1;i < n;i++){
            if(prices[i] > prices[i-1]){
                sum += prices[i] - prices[i-1];
            }
        }
        return sum;
    }
    int maxProfit(int k, vector<int> &prices) {
        int n = prices.size();
        if(k >= n/2){
            return maxProfit_all(prices);    
        }
        int dp[2][n+1];
        memset(dp,0,sizeof(dp));
        for(int t = 1; t <= k; t++){
            int cur_max = 0x80000000;
            dp[t%2][0] = 0;
            for(int i = 0; i < n; i++){
                dp[t%2][i+1] = max(dp[(t+1)%2][i+1],max(dp[t%2][i],prices[i] + cur_max));
                cur_max = max(cur_max,dp[(t+1)%2][i] - prices[i]);
            }
        }
        return dp[k%2][n];
    }
};
