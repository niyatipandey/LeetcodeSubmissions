class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        int area =0;
        int maxArea = 0;
        int n = heights.size();

        for(int i=0;i<=heights.size();i++){
            int currHeight = (i == n) ? 0 : heights[i];
            while(!st.empty() && currHeight < heights[st.top()]){
                int p = st.top();
                st.pop();
                int width;
                if(st.empty()){
                    width = i;
                }
                else{
                    width = i-st.top()-1;
                }
                area = heights[p] * width;
                maxArea = max(maxArea,area);
            }
            if(i < n){
                st.push(i);
            }
        }
        return maxArea;
    }
};