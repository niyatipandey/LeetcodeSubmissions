class Solution {
public:
    int f(int m,int n,int i,int j,vector<vector<int>>&dp,vector<vector<int>>& obstacleGrid){
        if(i >=m || j >= n){
            return 0;
        }
        if(obstacleGrid[i][j] == 1){
            return 0;
        }
        if(i == m-1 && j == n-1){
            return 1;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int right = 0;
        int bottom = 0;
        if(i+1 < m){
            bottom = f(m,n,i+1,j,dp,obstacleGrid);
        }
        if(j+1 < n){
            right = f(m,n,i,j+1,dp,obstacleGrid);
        }
        return dp[i][j] = right + bottom;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return f(m,n,0,0,dp,obstacleGrid);
    }
};