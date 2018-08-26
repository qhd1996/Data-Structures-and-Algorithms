/**
*假设定义 f[i] 为以第 i 个元素为终点的最长递增子序列，那么如果 j<i 且 nums[j]<nums[i] ，则 f[i] 一定是 f[j] 的前缀。
*f[i] = max{f[j] when exists 0<= j < i && nums[j] < nums[i], 0 else} + 1
**/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty()) 
            return 0;
        vector<int> f(nums.size(), 1);
        int global=1;
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    f[i]=max(f[i],f[j]+1);
                }
            }
            global=max(global,f[i]);
        }
        return global;
    }
};
