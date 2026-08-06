class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));

        for(int target = 0;target<=amount ; target++){
            if(target % coins[0] == 0){
                dp[0][target] = target/coins[0];
            }else{
                dp[0][target] = INT_MAX;
            }
        }

        for(int i=1;i<n;i++){
            for(int target = 0;target <= amount;target++){
                int notTake = dp[i-1][target];
                int take = INT_MAX;
                if(coins[i] <= target){
                    if (dp[i][target - coins[i]] != INT_MAX) {
                        take = dp[i][target - coins[i]] + 1;
                    }
                }
                dp[i][target] = min(take,notTake);
            }
        }

        if(dp[n-1][amount] == INT_MAX){
            return -1;
        }

        return dp[n-1][amount];

    }
};