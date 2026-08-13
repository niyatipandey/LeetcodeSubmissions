class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int left = -1;
        int right = -1;
        int low =0;
        int high =n-1;
        vector<int>ans;

        while(low <= high){
            int mid = low + (high-low)/2;
            if(nums[mid] == target){
                left = mid;
                high = mid-1;
            }
            else if(nums[mid] > target){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        low =0;
        high = n-1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(nums[mid] == target){
                right = mid;
                low = mid+1;
            }
            else if(nums[mid] > target){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        ans.push_back(left);
        ans.push_back(right);
        return ans;

    }
};