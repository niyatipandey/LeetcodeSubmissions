class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        int n = heights.size();
        int ans =0;
        int height =0;
        int width =0;
        if(heights.size() == 1){
            return heights[0];
        }
        for(int i=0;i<=n;i++){

            int currHeight = (i == n) ? 0 : heights[i];
            while(!st.empty() && currHeight < heights[st.top()]){
                height = heights[st.top()];
                st.pop();

                if(st.empty()){
                    width = i;
                }else{
                    width = i-st.top()-1;
                }

                ans = max(ans,height*width);
            }
            if(i < n){
                st.push(i);
            }
        }
        return ans;
    }
};