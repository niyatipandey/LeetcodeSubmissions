class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mpp;
        for(char x : s){
            mpp[x]++;
        }
        priority_queue<pair<int,char>,vector<pair<int,char>>>pq;

        for(auto it : mpp){
            int freq = it.second;
            int node = it.first;

            pq.push({freq,node});
        }
        string ans = "";

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            int freq = it.first;
            char x = it.second;
            while(freq > 0){
                ans += x;
                freq--;
            }
        }
        return ans;
    }
};