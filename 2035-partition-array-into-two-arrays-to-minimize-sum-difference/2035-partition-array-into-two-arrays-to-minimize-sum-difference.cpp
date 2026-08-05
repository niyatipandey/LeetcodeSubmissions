class Solution {
public:
    void generate(int idx, int count, int sum,vector<int>& arr,vector<vector<int>>&store){
        if(idx == arr.size()){
            store[count].push_back(sum);
            return; 
        }

        generate(idx+1,count,sum,arr,store);
        generate(idx+1,count+1,sum+arr[idx],arr,store);
    }

    int minimumDifference(vector<int>& nums) {
        int n = nums.size() /2;
        int totalSum =0;

        for(int i=0;i<nums.size();i++){
            totalSum += nums[i];
        }

        vector<int>left(nums.begin(),nums.begin()+n);
        vector<int>right(nums.begin()+n,nums.end());

        vector<vector<int>>leftSum(n+1);
        vector<vector<int>>rightSum(n+1);

        generate(0,0,0,left,leftSum);
        generate(0,0,0,right,rightSum);

        for(int i=0;i<=n;i++){
            sort(rightSum[i].begin(),rightSum[i].end());
        }

        int ans = INT_MAX;

        for(int i=0;i<=n;i++){
            for(int leftVal : leftSum[i]){
                int target = (totalSum/2.0) - leftVal;

                auto& vec = rightSum[n-i];

                int requiredDiff = 0;

                auto it = lower_bound(vec.begin(),vec.end(),target);

                if(it != vec.end()){
                    requiredDiff = abs(totalSum - 2*(*it + leftVal));
                    ans = min(ans,requiredDiff);
                }
                if(it != vec.begin()){
                    auto prevIt = prev(it);
                    requiredDiff = abs(totalSum - 2*(*prevIt + leftVal));
                    ans = min(ans,requiredDiff);
                }
            }
        }

        return ans;
        
    }
};