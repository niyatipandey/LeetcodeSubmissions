class Solution {
public:
    void subsetSum(vector<int>& candidates,int target,int sum,vector<vector<int>>&ans,vector<int>&res,int idx,int n){
        if(sum > target){
            return;
        }
        if(idx == n){
            if(sum == target){
                ans.push_back(res);
            }
            return;
        }
        
        res.push_back(candidates[idx]);
        subsetSum(candidates,target,sum+candidates[idx],ans,res,idx,n);
        res.pop_back();

        subsetSum(candidates,target,sum,ans,res,idx+1,n);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int sum = 0;
        vector<vector<int>>ans;
        vector<int>res;
        int n = candidates.size();
        subsetSum(candidates,target,sum,ans,res,0,n);

        return ans;
    }
};