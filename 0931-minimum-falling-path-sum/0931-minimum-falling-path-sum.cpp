class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int>dp = matrix[n-1];

        for(int row = n-2 ; row >=0 ; row--){
            vector<int>curr(n);

            for(int col = 0;col<n;col++){
                int first = INT_MAX;
                int second = dp[col];
                int third = INT_MAX;

                if(col-1 >= 0){
                    first = dp[col-1];
                }
                if(col +1 < n){
                    third = dp[col+1];
                }

                curr[col] = matrix[row][col] + min(first, min(second,third));
            }
            dp = move(curr);
        }
        return *min_element(dp.begin(),dp.end());
    }
};