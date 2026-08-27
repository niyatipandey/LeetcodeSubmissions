class Solution {
public:
    void solve(vector<int>& nums,vector<vector<int>>&result,vector<int>& arr,int idx,int n){
        if(idx == n){
            result.push_back(arr);
            return;
        }
        arr.push_back(nums[idx]);
        solve(nums,result,arr,idx+1,n);
        arr.pop_back();
        
        solve(nums,result,arr,idx+1,n);
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>result;
        vector<int>arr;
        solve(nums,result,arr,0,n);
        return result;
    }
};