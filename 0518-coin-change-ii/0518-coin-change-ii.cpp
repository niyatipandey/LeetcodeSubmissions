class Solution {
public:
    int check(vector<int>& coins, int amount,int idx,vector<vector<int>>&dp){
        if(amount == 0){
            return 1;
        }
        if(idx == 0){
            if(amount % coins[0] == 0){
                return 1;
            }
            return 0;
        }
        if(dp[idx][amount] != -1){
            return dp[idx][amount];
        }

        int notTake = check(coins,amount,idx-1,dp);
        int take = 0;
        if(amount >= coins[idx]){
            take = check(coins,amount-coins[idx],idx,dp);
        }

        return dp[idx][amount] = take + notTake;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return check(coins,amount,n-1,dp);
    }
};