class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>freq;
        
        int i=0;
        int j=0;
        int distinct =0;
        long long ans = 0;
        long long sum =0;
        while(j < n){
            if(freq[nums[j]]==0){
                distinct++;
            }
            freq[nums[j]]++;
            sum += nums[j];
            while(j-i+1 > k){
                sum -= nums[i];
                freq[nums[i]]--;
                if(freq[nums[i]]==0){
                    distinct--;
                }
                i++;
            }
            if(j-i+1 == k && distinct == k){
                ans = max(ans,sum);
            }
            j++;
        }
        return ans;
    }
};