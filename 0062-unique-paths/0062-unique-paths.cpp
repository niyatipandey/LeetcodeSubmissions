class Solution {
public:
    int totalPath(int i,int j,int m,int n,vector<vector<int>>&dp){
        if(i == m && j == n){
            return 1;
        }
        if(i < 0 || i > m || j < 0 || j > n){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int right = totalPath(i,j+1,m,n,dp);
        int left = totalPath(i+1,j,m,n,dp);

        return dp[i][j] = right+ left;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return totalPath(0,0,m-1,n-1,dp);
    }
};