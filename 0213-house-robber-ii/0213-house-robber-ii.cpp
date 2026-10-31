class Solution {
public: 
    int houseRob(vector<int>&nums,int n,vector<int>&dp,int idx){
        if(idx >= n){
            return 0;
        }
        if(dp[idx] != -1){
            return dp[idx];
        }
        int take = houseRob(nums,n,dp,idx+2) + nums[idx];
        int notTake = houseRob(nums,n,dp,idx+1);

        return dp[idx] = max(take,notTake);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }
        vector<int>dp1(n+1,-1);
        vector<int>dp2(n+1,-1);
        int skipLast = houseRob(nums,n-1,dp1,0);
        int skipFirst = houseRob(nums,n,dp2,1);

        return max(skipLast,skipFirst);
    }
};