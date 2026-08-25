class Solution {
public:
    double func(vector<int>&nums){
        if(nums.size() == 0){
            return 0;
        }

        int left = 0;
        int right =nums.size()-1;

        int mid = left + (right-left)/2;
        if(nums.size() % 2 != 0){
            return nums[mid];
        }
        return ((double)nums[mid] + nums[mid+1])/2;
        
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int>merged ;
        int x = 0;
        int y = 0;
        while(x < n && y < m){
            if(nums1[x] < nums2[y]){
                merged.push_back(nums1[x]);
                x++;
            }else{
                merged.push_back(nums2[y]);
                y++;
            }
        }
        while(x < n){
            merged.push_back(nums1[x++]);
        }
        while(y < m){
            merged.push_back(nums2[y++]);
        }
        double val = func(merged);
        return val;
    }
};