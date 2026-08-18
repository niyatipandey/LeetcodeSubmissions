class Solution {
public:
    bool func(vector<int>& nums, int k,int maxSum){
        int sum =0;
        int count =1;
        for(int i=0;i<nums.size();i++){
            if(sum + nums[i] > maxSum){
                sum = nums[i];
                count++;
            }else{
                sum += nums[i];
            }
        }
        return count <= k;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int sum =0;
        for(int i=0;i<n;i++){
            sum += nums[i];
        }
        
        int low = *max_element(nums.begin(), nums.end());
        int high = sum;
        int ans =0;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(func(nums,k,mid)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};