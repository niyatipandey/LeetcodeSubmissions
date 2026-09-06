class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mpp;

        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }

        int x = nums.size()/2;
        int ans = 0;

        for(int i=0;i<nums.size();i++){
            if(mpp[nums[i]] > x){
                ans = nums[i];
            }
        }
        return ans;
    }
};