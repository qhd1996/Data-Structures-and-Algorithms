//状态方程f(i,j)=min{f(i+1,j),f(i+1,j+1)}+(i,j)
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int size=triangle.size();
        for(int i=size-2;i>=0;i--){
            for(int j=0;j<i+1;j++){
                triangle[i][j]+=min(triangle[i+1][j],triangle[i+1][j+1]);
            }
        }
        return triangle[0][0];
    }
};
