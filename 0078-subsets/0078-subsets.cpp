class Solution {
public:
    void recurseSet(vector<vector<int>>& ans,int n ,vector<int>& nums,int idx,vector<int>&res){
        if(idx == n){
            ans.push_back(res);
            return;
        }

        res.push_back(nums[idx]);
        recurseSet(ans,n,nums,idx+1,res);
        res.pop_back();

        recurseSet(ans,n,nums,idx+1,res);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>ans;
        vector<int>res;
        recurseSet(ans,n,nums,0,res);
        return ans;
    }
};