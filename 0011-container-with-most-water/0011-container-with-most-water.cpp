class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i=0;
        int j= n-1;
        int area = INT_MIN;
        int l,b = 0;
        while(i<j){
            if(height[i] < height[j]){
                l = j-i;
                b = height[i];
                area = max(area ,l*b );
                i++;
            }else if(height[i] >= height[j]){
                l = j-i;
                b = height[j];
                area = max(area ,l*b );
                j--;
            }
        }
        return area;
    }
};