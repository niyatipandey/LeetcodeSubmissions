class Solution {
public:
    int f(int i,int j,int m,int n,vector<vector<int>>& grid,vector<vector<int>>& dp){
        int mini = INT_MAX;
        if( i >= m || j>= n){
            return INT_MAX;
        }
        if( i == m-1 && j == n-1){
            return dp[i][j] = grid[m-1][n-1];
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int right = f(i,j+1,m,n,grid,dp);
        int bottom = f(i+1,j,m,n,grid,dp);
        mini = grid[i][j] + min(right,bottom);

        return dp[i][j] = mini;
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return f(0,0,m,n,grid,dp);
    }
};