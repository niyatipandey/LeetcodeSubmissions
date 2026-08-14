class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>>result;
        vector<int>ans;

        for(int k =0;k<n;k++){
            if( k > 0 && nums[k] == nums[k-1]){
                continue;
            }

            int j =n-1;
            int i = k+1;
            while(i < j){

                if(nums[i] + nums[j] == -(nums[k])){
                    ans.push_back(nums[k]);
                    ans.push_back(nums[i]);
                    ans.push_back(nums[j]);
                    result.push_back(ans);
                    ans.clear();
                    i++;
                    j--;

                    while( i < j && nums[i] == nums[i-1]){
                        i++;
                    }
                    while(i< j && nums[j] == nums[j+1]){
                        j--;
                    }
                }else if(nums[i] + nums[j] > -(nums[k])){
                    j--;
                }else{
                    i++;
                }  
            }
        }
        return result;
    }
};