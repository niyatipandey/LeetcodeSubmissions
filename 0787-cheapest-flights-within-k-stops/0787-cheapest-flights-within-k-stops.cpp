class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);

        for(auto flight : flights){
            int u = flight[0];
            int v = flight[1];
            int w = flight[2];

            adj[u].push_back({v,w});
        }

        vector<int>dist(n,1e9);
        dist[src] = 0;
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src,0}}); //stop node dist

        while(!q.empty()){
            int stop = q.front().first;
            int node = q.front().second.first;
            int distance = q.front().second.second;
            q.pop();

            if(stop > k){
                continue;
            }
            
            for(auto it : adj[node]){
                int adjNode = it.first;
                int weight = it.second;

                int newDist = distance + weight;
                if(newDist < dist[adjNode]){
                    dist[adjNode] = newDist;
                    q.push({stop+1,{adjNode,dist[adjNode]}});
                }
            }
        }
        if(dist[dst] != 1e9){
            return dist[dst];
        }
        return -1;

    }
};