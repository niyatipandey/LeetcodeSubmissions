class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int i =0;
        int j =0;
        int n = nums.size();
        int sum =0;
        int count=0;

        for(i =0; i<n; i++){
            sum =0;
            for(j =i;j<n;j++){
                sum += nums[j];
                if(sum == k){
                    count++;
                }
            }
        }
        return count;
    }
};