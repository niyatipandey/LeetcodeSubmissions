class Solution {
public:
    int houseClimb(vector<int>&dp,int i,int n){
        if(i > n){
            return 0;
        }
        if(i == n){
            return 1;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        int oneStep = houseClimb(dp,i+1,n);
        int twoStep = houseClimb(dp,i+2,n);

        return dp[i] = oneStep + twoStep;
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return houseClimb(dp,0,n);
    }
};