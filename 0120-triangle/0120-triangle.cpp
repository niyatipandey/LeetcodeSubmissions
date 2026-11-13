class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size() == 1){
            return triangle[0][0];
        }
        int n = triangle.size();
        vector<int>dp = triangle[n-1];

        for(int i=n-2;i>=0;i--){
            vector<int>curr(i+1);
            for(int col = 0;col <= i; col++){
                int first = dp[col];
                int second = dp[col+1];

                curr[col] = triangle[i][col] + min(first,second);
            }
            dp = move(curr);
        }
        return dp[0];
    }
};