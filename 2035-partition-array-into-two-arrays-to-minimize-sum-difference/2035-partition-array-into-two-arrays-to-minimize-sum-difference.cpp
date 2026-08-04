class Solution {
public:
    void generate(int index,int count,int sum,vector<int>& arr,vector<vector<int>>& store){

        if(index == arr.size()){
            store[count].push_back(sum);
            return;
        }

        generate(index+1,count,sum,arr,store);
        generate(index+1,count+1,sum+arr[index],arr,store);

    }
    int minimumDifference(vector<int>& nums) {
        int n = nums.size()/2;
        int totalSum=0;
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

        for(int k=0;k<=n;k++){
            for(int leftVal : leftSum[k]){
                auto &vec = rightSum[n-k];

                double target = (totalSum/2.0) - leftVal;

                auto it = lower_bound(vec.begin(),vec.end(),target);
                int chosenSum = 0;

                if(it != vec.end()){
                    chosenSum = leftVal + *it;
                    ans = min(ans, abs(totalSum - 2*chosenSum));
                }
                if(it != vec.begin()){
                    auto prevIt = prev(it);
                    chosenSum = leftVal + *prevIt;
                    ans = min(ans,abs(totalSum - 2*chosenSum));
                }
            }
        }
        return ans;
    }

};