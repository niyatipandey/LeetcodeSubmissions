class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l = 0;
        int r = n-1;
        int maxLeft =height[0];
        int maxRight =height[n-1];
        int water =0;

        while(l < r){
            if(height[l] < height[r]){
                maxLeft = max(maxLeft,height[l]);
                water += (maxLeft - height[l]);
                l++;
            }else{
                maxRight = max(maxRight,height[r]);
                water += (maxRight - height[r]);
                r--;
            }
        }

        return water;
    }
};