class Solution {
public:
    int f(int i,int j,int row,vector<vector<int>>& triangle,vector<vector<int>>& dp){
        if(i <0 || i>row || j<0 || j>i){
            return 1e8;
        }
        if(i == row-1){
            return dp[i][j] = triangle[i][j];
        }
        if(dp[i][j] != 1e8){
            return dp[i][j];
        }
        int justMax = f(i+1,j,row,triangle,dp);
        int sideMax = f(i+1,j+1,row,triangle,dp);

        int mini = min(justMax,sideMax) + triangle[i][j];

        return dp[i][j] = mini;
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        vector<vector<int>>dp(row,vector<int>(row,1e8));

        for(int i=row-1;i>=0;i--){
            for(int j=i;j>=0;j--){
                if(i == row-1){
                    dp[i][j] = triangle[i][j];
                    continue;
                }

                int justMax = dp[i+1][j];
                int sideMax = dp[i+1][j+1];

                int mini = min(justMax,sideMax);
                dp[i][j] = mini + triangle[i][j] ;
            }
        }

        return dp[0][0];
    }
};