class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_set<int>st;

        int i=0;
        int j=0;
        int n = nums.size();
        long long sum = 0;
        long long res =0;

        while(j<n){
            if(st.find(nums[j]) == st.end()){
                st.insert(nums[j]);
                sum += nums[j];
                j++;
            }
            else if(st.find(nums[j]) != st.end()){
                st.erase(nums[i]);
                sum -= nums[i];
                i++;
            }
            if(j-i == k){
                res  = max(res,sum);
                sum -= nums[i];
                st.erase(nums[i]);
                i++;
            }
        }
        return res;
    }
};