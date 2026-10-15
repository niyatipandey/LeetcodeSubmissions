class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto flight : flights){
            int from = flight[0];
            int to = flight[1];
            int price = flight[2];

            adj[from].push_back({to,price});
        }
        vector<int>dist(n,1e9);
        dist[src] =0;
        queue<pair<int,int>>q;
        int stops =0;
        q.push({src,0});
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                int city = q.front().first;
                int distance = q.front().second;
                q.pop();

                if(stops > k){
                    continue;
                }

                for(auto it : adj[city]){
                    int adjCity = it.first;
                    int weight = it.second;
                    if(distance + weight < dist[adjCity]){
                        dist[adjCity] = distance + weight;
                        q.push({adjCity,dist[adjCity]});
                    }
                }
            }
            stops++;
        }
        if(dist[dst] == 1e9){
            return -1;
        }
        return dist[dst];
    }
};