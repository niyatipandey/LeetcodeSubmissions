class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mpp;
        for(int i=0;i<s.length();i++){
            mpp[s[i]]++;
        }

        priority_queue<pair<int,char>,vector<pair<int,char>>,greater<pair<int,char>>>pq;

        for(auto [ele,freq] : mpp){
            pq.push({freq,ele});
        }

        string k = "";

        while(!pq.empty()){
            int freq = pq.top().first;
            while(freq > 0){
                char top = pq.top().second;
                k += top;
                freq--;
            }    
            pq.pop();
        }
        reverse(k.begin(),k.end());
        return k;
    }
};