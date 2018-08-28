class Solution {
public:
    int maxProfit(int k, vector<int> &prices) {
        int N = prices.size();
        if (k == 0 || N < 2) return 0;
        
        if (k > N / 2) {
            int sum = 0;
            for (int i = 1; i < N; i++){
                if (prices[i] > prices[i - 1]){
                    sum += prices[i] - prices[i - 1];
                }
            }
            return sum;
        }
        
        vector<int> buy(k + 1, INT_MIN);
        vector<int> sell(k + 1, 0);
        for (int i = 0; i< N; ++i) {
            for (int j = 1; j <= k; ++j) {
                buy[j] = max(buy[j], sell[j - 1] - prices[i]);
                sell[j] = max(sell[j], buy[j] + prices[i]);
            }
        }
        return sell[k];
    }
};
