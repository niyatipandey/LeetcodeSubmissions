class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        mpp[0]= -1;
        int prefixSum =0;

        for(int i=0;i<nums.size();i++){
            prefixSum += nums[i];

            int rem = prefixSum % k;

            if(mpp.find(rem) == mpp.end()){
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