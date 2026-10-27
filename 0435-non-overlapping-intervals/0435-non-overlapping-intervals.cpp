class Solution {
public:
    static bool compare(pair<int,int>&a,pair<int,int>&b){
        return a.first < b.first;
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int overlapping = 0;

        vector<pair<int,int>>arr;

        for(auto vec : intervals){
            int v1 = vec[0];
            int v2 = vec[1];

            arr.push_back({v1,v2});
        }
        sort(arr.begin(),arr.end(),compare);
        vector<pair<int,int>>res;
        int n = arr.size();

        int lastUsed = arr[0].second;
        int count = 1;
        for(int i=1;i<n;i++){
            if(lastUsed > arr[i].first){
                lastUsed = min(lastUsed,arr[i].second);
            }else{
                count++;
                lastUsed = arr[i].second;
            }
        }

        return intervals.size() - count;
    }
};