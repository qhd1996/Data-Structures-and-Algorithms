/**这可以转化为最大M子段和问题
*N个整数组成的序列a[1],a[2],a[3],…,a[n]，将这N个数划分为互不相交的M个子段，并且这M个子段的和是最大的。如果M >= N个数中正数的个数，那么输出所有正数的和。
*设dp[i][j]表示将前i个数分成j段（且必须以第i个数结尾）的最大子段和。
*d[i][j]=max(d[i][j-1])+a[j],max(d[k][j-1])+a[i])
*这里M=1
**/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxPro=0;
        int minPrice=INT_MAX;
        for(int i=0;i<prices.size();i++){
            minPrice=min(minPrice,prices[i]);
            maxPro=max(maxPro,prices[i]-minPrice);
        }
        return maxPro;
    }
};
