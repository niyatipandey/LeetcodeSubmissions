class Solution {
public:
    int jump(vector<int>& nums) {
        int count = 0;
        int maxJump = 0;
        int currIdx = 0;
        for(int i=0;i<nums.size()-1;i++){
            maxJump = max(maxJump , nums[i] + i);

            if(i == currIdx){
                count++;
                currIdx = maxJump;
            }
        }
        return count;
    }
};