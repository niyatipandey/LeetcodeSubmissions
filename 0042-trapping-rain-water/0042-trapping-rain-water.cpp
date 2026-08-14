class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int maxleft = height[0];
        int maxright = height[n-1];

        int l =0;
        int r = n-1;
        int water =0;

        while(l < r){
            if(height[l] < height[r]){
                maxleft = max(maxleft,height[l]);
                water += (maxleft - height[l]);
                l++;
            }else{
                maxright = max(maxright,height[r]);
                water += (maxright - height[r]);
                r--;
            }
        }
        return water;
    }
};