class Solution {
public:
    int generate(vector<int>& nums, int k){
        int n = nums.size();
        int i=0;
        int j = 0;
        int count =0;
        int distinct = 0;
        int maxNum =0;
        for(int i=0;i<n;i++){
            if(nums[i] > maxNum){
                maxNum = nums[i];
            }
        }
        vector<int>freq(maxNum+1,0);

        while(j < n){
            if(freq[nums[j]]==0){
                distinct++;
            }
            freq[nums[j]]++;
            while(distinct > k){
                freq[nums[i]]--;
                if(freq[nums[i]]==0){
                    distinct--;
                }
                i++;
            }
            count += (j-i+1);
            j++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return generate(nums,k) - generate(nums,k-1);
    }
};