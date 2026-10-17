class Solution {
public:
    int manDistance(vector<vector<int>>& points,int p1,int p2){
        return abs(points[p1][0] - points[p2][0]) + abs(points[p1][1] - points[p2][1]);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<int>vis(n,0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        int minCost = 0;

        while(!pq.empty()){
            auto it = pq.top();
            int wt = it.first;
            int node = it.second;
            pq.pop();

            if(vis[node]){
                continue;
            }
            vis[node] = 1;
            minCost += wt;

            for(int i=0;i<n;i++){
                if(!vis[i]){
                    int dist = manDistance(points,node,i);
                    pq.push({dist,i});
                }
            }
        }

        return minCost;
    }
};