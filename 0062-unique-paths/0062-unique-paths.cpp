class Solution {
public:
    int f(int m,int n,vector<vector<int>>&dp,int i,int j){
        if(i == m-1 && j == n-1){
            return 1;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int bottom = 0;
        int right = 0;
        if(j < n){
            right = f(m,n,dp,i,j+1);
        }
        if(i < m){
            bottom = f(m,n,dp,i+1,j);
        }
        return dp[i][j] = right + bottom;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return f(m,n,dp,0,0);
    }
};