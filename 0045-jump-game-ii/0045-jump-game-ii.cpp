class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return 0;
        }
        int maxJump =0 ;
        int count =0;
        int currEnd = 0;

        for(int i=0;i<n-1;i++){
            maxJump = max(maxJump , i + nums[i]);
        
            if(i == currEnd){
                count++;
                currEnd = maxJump;
            }
        }
        return count;
    }
};