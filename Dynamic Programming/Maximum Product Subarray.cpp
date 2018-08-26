/**
*这题跟“最大连续子序列和”非常类似，只不过变成了“最大连续子序列积”，所以解决思路也很类似。
*仅仅有一个小细节需要注意，就是负负得正，两个负数的乘积是正数，因此我们不仅要跟踪最大值，还要跟踪最小值。
**/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxLocal=nums[0];
        int minLocal=nums[0];
        int globalMax=nums[0];
        for(int i=1;i<nums.size();i++){
            int temp=maxLocal;
            maxLocal=max(max(nums[i]*maxLocal,nums[i]),nums[i]*minLocal);
            minLocal=min(min(nums[i]*temp, nums[i]),nums[i]*minLocal);
            globalMax = max(globalMax, maxLocal);
        }
        return globalMax;
    }
};
