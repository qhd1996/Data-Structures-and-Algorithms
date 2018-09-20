//贪心法，低进高出，把所有正的价格差相加起来
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sum=0;
        for(int i=1;i<prices.size();i++){
            int diff=prices[i]-prices[i-1];
            if(diff>0) sum+=diff;
        }
        return sum;
    }
};
