class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        int prefixSum =0;
        int n = nums.size();
        mpp[0]= -1;

        for(int i=0;i<n;i++){
            prefixSum += nums[i];
            int rem = prefixSum % k;

            if(mpp.find(rem) == mpp.end()){ // == means notFound :: != means found
                mpp[rem] = i;
            }else{
                int j = mpp[rem];

                if(i - j >= 2){
                    return true;
                }
            }
        }
        return false;
    }
};