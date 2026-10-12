class Solution {
public:
    int bfs(int i,int j,vector<vector<int>>& dist,int n,int m,vector<vector<int>>& heights){
        dist[0][0] = 0;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{i,j}});
        int dr[4] = {1,0,-1,0};
        int dc[4] = {0,1,0,-1};

        while(!pq.empty()){
            int effort = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            if(effort > dist[row][col]){
                continue;
            }

            if(row == n-1 && col == m-1){
                return dist[n-1][m-1];
            }

            for(int i=0;i<4;i++){
                int newr = row + dr[i];
                int newc = col + dc[i];
                if(newr >=0 && newr<n && newc >=0 && newc <m){
                    int oldEffort = dist[newr][newc];
                    int diff = abs(heights[newr][newc] - heights[row][col]);
                    int candidate = max(effort,diff);
                    if(candidate < oldEffort){
                        dist[newr][newc] = candidate;
                        pq.push({dist[newr][newc],{newr,newc}});
                    }
                }
            }
        }
        return -1;
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>>dist(n,vector<int>(m,1e9));

        return bfs(0,0,dist,n,m,heights);
    }
};