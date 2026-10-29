class Solution {
public:
    int stair(vector<int>&dp,int n,int i){
        if(i > n){
            return 0;
        }
        if(i == n){
            return 1;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        int oneStair = stair(dp,n,i+1);
        int twoStair = stair(dp,n,i+2);

        return dp[i] = oneStair + twoStair;
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return stair(dp,n,0);
    }
};