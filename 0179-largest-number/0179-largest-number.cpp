class Solution {
public:
    static bool compare(string a,string b){
        return a+b > b+a;
    }
    string largestNumber(vector<int>& nums) {
        vector<string>ans;
        for(int i=0;i<nums.size();i++){
            ans.push_back(to_string(nums[i]));
        }

        sort(ans.begin(),ans.end(),compare);
        if(ans[0] == "0"){
            return "0";
        }
        string res = "";

        for(string x : ans){
            res.append(x);
        }
        return res;
    }
};