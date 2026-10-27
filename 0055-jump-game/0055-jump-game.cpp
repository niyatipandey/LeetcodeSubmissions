class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxJump = 0;
        for(int i=0;i<nums.size();i++){
            if(maxJump < i){
                return false;
            }
            maxJump = max(maxJump, i + nums[i]);
        }
        return true;
    }
};