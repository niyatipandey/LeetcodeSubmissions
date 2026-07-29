class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<long long>>dp(m,vector<long long>(n,0));
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(obstacleGrid[i][j] == 1){
                    dp[i][j] = 0;
                    continue;
                }
                if(i == m-1 && j == n-1){
                    dp[i][j] = 1;
                    continue;
                }
                long long right =0;
                long long bottom =0;
                if( i+1 < m ){
                    bottom = dp[i+1][j];
                }
                if( j+1 < n){
                    right = dp[i][j+1];
                }
                dp[i][j] = right+bottom;
            }
        }
        return (int)dp[0][0];
    }
};