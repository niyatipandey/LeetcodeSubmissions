class Solution {
public:
    int f(int m,int n,vector<vector<int>>&dp,vector<vector<int>>& grid,int i,int j){
        if(i == m-1 && j == n-1){
            return grid[i][j];
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int right = 1e9;
        int bottom = 1e9;
        if(i+1 < m){
            bottom = f(m,n,dp,grid,i+1,j);
        }
        if(j+1 < n){
            right = f(m,n,dp,grid,i,j+1);
        }
        return dp[i][j] = grid[i][j] + min(right,bottom);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return f(m,n,dp,grid,0,0);
    }
};