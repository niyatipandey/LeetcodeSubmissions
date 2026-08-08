class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();

        int i=0;
        int j=0;
        int sum =0;
        int ans =INT_MAX;
        bool found =false;

        while(i < n && j<n){
            sum += nums[j];

            while( sum >=target && i<=j){
                ans = min(ans,j-i+1);
                found = true;
                sum -= nums[i];
                i++;
            }
            j++;
        }
        if(!found){
            return 0;
        }
        return ans;
    }
};