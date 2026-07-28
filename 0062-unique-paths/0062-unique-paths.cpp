class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int>prev(n);

        for(int i=m-1;i>=0;i--){
            vector<int>curr(n);
            for(int j=n-1;j>=0;j--){
                if (i == m - 1 && j == n - 1){
                    curr[j]=1;
                }
                else{
                    int right =0;
                    int bottom =0;
                    if(j+1 < n){
                        right = curr[j+1];
                    }
                    if(i+1 < m){
                        bottom = prev[j];
                    }
                    curr[j] = right+bottom;
                }
            }
            prev=curr;
        }
        return prev[0];
    }
};