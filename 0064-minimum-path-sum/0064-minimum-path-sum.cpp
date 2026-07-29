class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int>prev(n);
        vector<int>curr(n);

        for(int i=m-1;i>=0 ;i--){
            for(int j=n-1;j>=0;j--){
                if( i == m-1 && j == n-1){
                    curr[j] = grid[m-1][n-1];
                    continue;
                }
                int right=INT_MAX;
                int bottom=INT_MAX;
                if( i+1 < m){
                    bottom = prev[j];
                }
                if(j+1 < n){
                    right = curr[j+1];
                }
                curr[j] = grid[i][j] + min(right,bottom);
            }
            prev=curr;
        }
        return curr[0];
    }
};