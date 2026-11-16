class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[0].size();

        vector<int>dp = triangle[n-1];

        for(int i=n-2;i>=0;i--){
            vector<int>curr(i+1);
            for(int j=0;j<i+1;j++){
                curr[j] = triangle[i][j] + min(dp[j] , dp[j+1]);
            }
            dp = move(curr);
        }
        return dp[0];
    }
};