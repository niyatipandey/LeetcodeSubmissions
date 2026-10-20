class Solution {
public:
    void subset(vector<int>& nums,vector<int>& res,vector<vector<int>>&ans,int idx,int n){
        ans.push_back(res);

        for(int i =idx;i<n;i++){
            if(i > idx && nums[i] == nums[i-1]){
                continue;
            }
            res.push_back(nums[i]);
            subset(nums,res,ans,i+1,n);
            res.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>res;
        int idx =0;
        sort(nums.begin(),nums.end());
        subset(nums,res,ans,idx,nums.size());
        return ans;
    }
};