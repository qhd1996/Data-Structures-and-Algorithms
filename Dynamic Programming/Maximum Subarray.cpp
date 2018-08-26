class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size= nums.size();
        int dp[size];
        dp[0]=nums[0];
        for(int i=1;i<size;i++){
            dp[i]=max(nums[i],dp[i-1]+nums[i]);
        }
        int k=0;
        for(int i=1;i<size;i++){
            if(dp[i]>dp[k]){
                k=i;
            }
        }
        return dp[k];
    }
};
