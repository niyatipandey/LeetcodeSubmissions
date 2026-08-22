class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        vector<int>ans;
        int n = nums.size();
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for (auto [ele, freq] : mpp){
            pq.push({freq,ele});
            if(pq.size() > k){
                pq.pop();
            }
        }
        while(!pq.empty()){
            int top = pq.top().second;
            ans.push_back(top);
            pq.pop();
        }
        return ans;

    }
};