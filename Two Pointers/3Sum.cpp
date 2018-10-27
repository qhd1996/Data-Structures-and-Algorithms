**
*再左右夹逼，时间复杂度是O(n^2)
*这个方法可以推广到k-sum，先排序，然后做k-2次循环，在最内层循环左右夹逼，时间复杂度是O(max{nlogn,n^k-1})
**

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.size()<3) return result;
        sort(nums.begin(),nums.end());
        const int target=0;;
        
        auto last=nums.end();
        for(auto i=nums.begin();i<last-2;i++){
            auto j=i+1;
            if(i>nums.begin()&&*i==*(i-1)) continue;
            auto k=last-1;
            while(j<k){
                if(*i+*j+*k<target){
                    j++;
                    while(*j==*(j-1)&&j<k) j++;
                }else if(*i+*j+*k>target){
                    k--;
                    while(*k==*(k+1)&&j<k) k--;
                }else{
                    result.push_back({*i,*j,*k});
                    j++;
                    k--;
                    while(*j==*(j-1)&&*k==*(k+1)&&j<k)
                        j++;
                }
            }
        }
        return result;
    }
};
