class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>>pq;

        for(auto it : mpp){
            int freq = it.second;
            int val = it.first;

            pq.push({freq,val});
        }
        vector<int>ans;
        while(!pq.empty() && k > 0){
            auto it = pq.top();
            pq.pop();

            int val = it.second;
            ans.push_back(val);
            k--;
        }
        return ans;
    }
};