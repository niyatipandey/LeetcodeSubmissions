class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_set<int>st;
        int i=0;
        int j=0;
        int n = nums.size();
        long long sum =0;
        long long ans= 0;

        while(j<n){
            while(st.find(nums[j]) != st.end()){
                st.erase(nums[i]);
                sum -= nums[i];
                i++;
            }

            sum += nums[j];
            st.insert(nums[j]);
            while(j-i+1 > k){
                st.erase(nums[i]);
                sum -= nums[i];
                i++;
            }
            if(j-i+1 == k){
                ans = max(ans,sum);
            }
            j++; 
        }
        return ans;
    }
};