class Solution {
public:
    const int INF = 1e9;
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<vector<int>>dp(m,vector<int>(m,INF));
        for(int i=m-1;i>=0;i--){
            for(int j=i;j>=0;j--){
                if(i == m-1){
                    dp[i][j] = triangle[i][j];
                    continue;
                }
                int rightBelow =dp[i+1][j+1];
                int justBelow =dp[i+1][j];

                dp[i][j] = triangle[i][j] + min(justBelow,rightBelow);
            }
        }
        return dp[0][0];
    }

};