class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        
        for(int k = 0;k<n;k++){
            int leftSum = 0;
            for(int i = 0; i<k;i++){
                leftSum += nums[i];
            }
            int rightSum =0;
            for(int j = k+1;j<n;j++){
                rightSum += nums[j];
            }
            if(leftSum == rightSum){
                return k;
            }
        }
        return -1;
    }
};