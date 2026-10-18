class Solution {
    struct Compare {
        bool operator()(const pair<int,string>& a,
                        const pair<int,string>& b) const {
            if (a.first == b.first) {
                return a.second > b.second;
            }
            return a.first < b.first;
        }
    };
    
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        priority_queue<pair<int,string>,vector<pair<int,string>>,Compare>pq;
        unordered_map<string,int>mpp;

        for(int i=0;i<words.size();i++){
            mpp[words[i]]++;
        }

        for(auto it : mpp){
            string word = it.first;
            int freq = it.second;

            pq.push({freq,word});
        }
        vector<string>ans;
        while(!pq.empty() && k > 0){
            auto it = pq.top();
            pq.pop();

            int freq = it.first;
            string node = it.second;

            ans.push_back(node);
            k--;
        }
        
        return ans;
    }
};