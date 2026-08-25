class Solution {
public:
    int robHouse(vector<int>& nums,int idx,vector<int>& dp){
        if( idx == 0){
            return dp[0] = nums[0];
        }
        if(idx == 1){
            return dp[1] = max(nums[0],nums[1]);
        }
        if(dp[idx] != -1){
            return dp[idx];
        }

        int take = robHouse(nums,idx -2,dp) + nums[idx];
        int notTake = robHouse(nums,idx-1,dp);

        return dp[idx] = max(take,notTake);
    }

    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return robHouse(nums,nums.size()-1,dp);
    }
};