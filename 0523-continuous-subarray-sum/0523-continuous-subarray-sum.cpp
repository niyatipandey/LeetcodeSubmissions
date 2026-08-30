class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        vector<int>prefix(nums.size()+1,0);
        unordered_map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            prefix[i+1] = prefix[i] + nums[i];
        }
        
        int sum =0;
        for(int i=0;i<=nums.size();i++){
            int remainder = prefix[i] % k;
            if(mpp.find(remainder) == mpp.end()){
                mpp[remainder] = i;
            }
            else{
                int j = mpp[remainder];
                if(i-j >= 2){
                    return true;
                }
            }
        }
        return false;
    }
};