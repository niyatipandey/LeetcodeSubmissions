class Solution {
public:
    int func(int left , int right , vector<int>& nums, int target){
        if(left > right){
            return -1;
        }
        int mid = left + (right-left)/2;
        if(nums[mid] == target){
            return mid;
        }else if(nums[mid] < target){
            return func(mid+1,right,nums,target);
        }
        return func(left,mid-1,nums,target);
    }
    int search(vector<int>& nums, int target) {
        int left= 0;
        int right= nums.size() -1;

        return func(left,right,nums,target);
    }
};