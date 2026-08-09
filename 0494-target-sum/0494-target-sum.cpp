class Solution {
public:
    int generate(int sum,int idx,int n, int target,vector<int>& nums,vector<vector<int>>&dp){
        if(idx == n){
            return sum == target;
        }
        if(sum > target){
            return 0;
        }
        if(dp[idx][sum] != -1){
            return dp[idx][sum];
        }
        int notTake = generate(sum,idx+1, n,target,nums,dp);
        int take = generate(sum+nums[idx],idx+1,n,target,nums,dp);

        return dp[idx][sum] = take+notTake;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totalSum =0;
        for(int i=0;i<n;i++){
            totalSum += nums[i];
        }
        if(totalSum + target < 0 || (totalSum + target) % 2 != 0){
            return 0;
        }
        int requiredSum = (totalSum + target)/2;
        vector<vector<int>>dp(n,vector<int>(requiredSum+1,-1));
        return generate(0,0,n,requiredSum,nums,dp);
    }
};