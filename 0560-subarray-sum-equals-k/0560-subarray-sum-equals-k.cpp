class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int sum =0;
        vector<int>prefix(n+1,0);
        for(int i=0;i<n;i++){
            prefix[i+1] = prefix[i] + nums[i];
        }
        unordered_map<int,int>mpp;
        int count =0;
        for(int i=0;i<=n;i++){
            
            sum = prefix[i];
            if(mpp.find(sum - k) != mpp.end()){
                count += mpp[sum -k];
            }

            mpp[prefix[i]]++;

        }

        return count;
    }
};