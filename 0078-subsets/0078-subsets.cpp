class Solution {
public:
    void subsetFunc(vector<vector<int>>& ans,vector<int>& res,vector<int>& nums,int idx ){
        if(idx == nums.size()){
            ans.push_back(res);
            return;
        }
        
        res.push_back(nums[idx]);
        subsetFunc(ans,res,nums,idx+1);
        res.pop_back();
        
        subsetFunc(ans,res,nums,idx+1);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>res;
        subsetFunc(ans,res,nums,0);
        return ans;
    }
};