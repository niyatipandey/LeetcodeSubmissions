class Solution {
public:
    bool check(vector<int>& nums,int target,int n,int idx,int sum,vector<vector<int>>&dp){
        if(sum > target){
            return false;
        }
        if(idx == n){
            if(target == sum){
                return true;
            }
            return false;
        }
        if(dp[idx][sum] != -1){
            return dp[idx][sum];
        }
        sum += nums[idx];
        int take = check(nums,target,n,idx+1,sum,dp);
        sum -= nums[idx];
        int notTake = check(nums,target,n,idx+1,sum,dp);

        return dp[idx][sum] = take || notTake;
    }

    bool canPartition(vector<int>& nums) {
        int target = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            target += nums[i];
        }
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        int sum = 0;
        if(target %2 != 0){
            return false;
        }

        return check(nums,target/2,n,0,sum,dp);
    }
};