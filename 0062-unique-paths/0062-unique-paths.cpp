class Solution {
public:
    int func(int m,int n,int r,int c,vector<vector<int>>&dp){
        if(r >= m || c >= n){
            return 0;
        }
        if(r == m-1 && c == n-1){
            return 1;
        }
        if(dp[r][c] != -1){
            return dp[r][c];
        }

        int right = func(m,n,r,c+1,dp);
        int down = func(m,n,r+1,c,dp);

        return dp[r][c] = right + down;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return func(m,n,0,0,dp);
    }
};