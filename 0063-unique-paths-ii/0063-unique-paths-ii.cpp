class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<long long>prev(n);
        vector<long long>curr(n);
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(obstacleGrid[i][j] == 1){
                    curr[j] = 0;
                    continue;
                }
                if(i == m-1 && j == n-1){
                    curr[j] = 1;
                    continue;
                }
                long long right =0;
                long long bottom =0;
                if( i+1 < m ){
                    bottom = prev[j];
                }
                if( j+1 < n){
                    right = curr[j+1];
                }
                curr[j] = right+bottom;
            }
            prev= curr;
        }
        return (int)prev[0];
    }
};