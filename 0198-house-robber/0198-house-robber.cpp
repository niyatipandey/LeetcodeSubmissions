class Solution {
public:
    int robHouse(vector<int>&nums,vector<int>&dp,int n,int i){
        if(i > n){
            return 0;
        }
        if(i == n){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }

        int take = robHouse(nums,dp,n,i+2) + nums[i];
        int notTake = robHouse(nums,dp,n,i+1);

        return dp[i] = max(take,notTake);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1,-1);

        return robHouse(nums,dp,n,0);
    }
};