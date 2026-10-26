class Solution {
public:
    static bool compare(pair<int,int>a,pair<int,int>b){
        return a.first < b.first;
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<pair<int,int>>arr;
        for(auto s : intervals){
            int u = s[0];
            int v = s[1];
            arr.push_back({u,v});
        }

        sort(arr.begin(),arr.end(),compare);
        int n = arr.size();
        
        if(arr.empty()){
            return {};
        }
        vector<vector<int>>res;
        int lastUsed = arr[0].second;
        int firstUsed = arr[0].first;
        for(int i=1;i<n;i++){
            if(lastUsed >= arr[i].first){
                lastUsed = max(lastUsed,arr[i].second);
            }else{
                res.push_back({firstUsed,lastUsed});
                firstUsed = arr[i].first;
                lastUsed = arr[i].second;
            }
        }
        res.push_back({firstUsed,lastUsed});

        return res;
    }
};