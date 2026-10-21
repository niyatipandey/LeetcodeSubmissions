class Solution {
public:
    void subsetSum(vector<int>& candidates,int target,int sum,vector<vector<int>>&ans,vector<int>&res,int idx,int n){
        if(sum == target){
            ans.push_back(res);
            return;
        }

        for(int i=idx;i<n;i++){
            if(i > idx && candidates[i] == candidates[i-1]){
                continue;
            }
            if (sum + candidates[i] > target) {
                break;
            }
            res.push_back(candidates[i]);
            subsetSum(candidates,target,sum+candidates[i],ans,res,i+1,n);
            res.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int sum = 0;
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>res;
        int n = candidates.size();
        subsetSum(candidates,target,sum,ans,res,0,n);

        return ans;
    }
};
