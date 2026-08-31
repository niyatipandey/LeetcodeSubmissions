class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        int  i =0;
        int j =0;
        vector<vector<int>>ans(m,vector<int>(n,0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int sum =0;
                int top = max(0,i-k);
                int bottom = min(m-1,i + k);
                int left = max(0,j-k);
                int right = min(n-1,j+k);

                for(int r= top; r <= bottom;r++){
                    for(int c= left; c <=right; c++){
                        sum += mat[r][c];
                    }
                }
                ans[i][j] = sum;
            }
        }
        return ans;
    }
};