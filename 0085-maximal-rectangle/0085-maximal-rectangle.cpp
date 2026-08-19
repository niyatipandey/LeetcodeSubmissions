class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        vector<int>height(col,0);
        int ans =0;

        for(int i = 0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j] == '1'){
                    height[j]++;
                }else{
                    height[j]=0;
                }
            }
            stack<int>st;
            for(int i=0;i<=col;i++){
                int currHeight = (i == col) ? 0 : height[i];
                while(!st.empty() && height[st.top()] > currHeight){
                    int h = height[st.top()];
                    st.pop();
                    int w;
                    if(st.empty()){
                        w= i;
                    }else{
                        w = i - st.top()-1;
                    }
                    ans = max(ans,h*w);
                }
                if(i<col){
                    st.push(i);
                }
            }
        }
        return ans;
    }
};