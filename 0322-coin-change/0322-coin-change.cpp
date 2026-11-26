class Solution {
public:
    int check(vector<int>& coins, int amount,int idx,vector<vector<int>>&dp){
        if(amount == 0){
            return 0;
        }
        if(idx == 0){
            if(amount % coins[0] == 0){
                return amount / coins[0];
            }
            return 1e9;
        }
        if(dp[idx][amount] != -1){
            return dp[idx][amount];
        }

        int notTake = check(coins,amount,idx-1,dp);
        int take = INT_MAX;
        if(amount >= coins[idx]){
            take = 1 + check(coins,amount-coins[idx],idx,dp);
        }

        return dp[idx][amount] = min(take,notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans =  check(coins,amount,n-1,dp);
        return ans >= 1e9 ? -1 : ans;
    }
};