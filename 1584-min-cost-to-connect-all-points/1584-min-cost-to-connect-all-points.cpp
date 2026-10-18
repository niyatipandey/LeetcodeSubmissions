class Solution {
public:
    int manHattanDist(vector<vector<int>>& points,int p1 ,int p2){
        return abs(points[p1][0] - points[p2][0]) + abs(points[p1][1] - points[p2][1]);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        int minWt = 0;
        vector<int>vis(n,0);

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            int dist = it.first;
            int node = it.second;

            if(vis[node]){
                continue;
            }
            vis[node] =1;
            minWt += dist;

            for(int i=0;i<n;i++){
                if(!vis[i]){
                    int manDist = manHattanDist(points,i,node);
                    pq.push({manDist,i});
                }
            }
        }
        return minWt;
    }
};