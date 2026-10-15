class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>dist(n,vector<int>(n,1e9));
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            dist[u][v] = w;
            dist[v][u] = w;
        }
        
        for(int i=0;i<n;i++){
            dist[i][i] = 0;
        }
        
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dist[i][k] != 1e9 && dist[k][j] != 1e9){
                        dist[i][j] = min(dist[i][j] , dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
        map<int,int>mpp;

        for(int i =0;i<n;i++){
            mpp[i]=0;
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i != j && dist[i][j] <= distanceThreshold){
                    mpp[i]++;
                }
            }
        }

        int ans = -1;
        int minCount = INT_MAX;

        for(auto it : mpp){
            int city = it.first;
            int count = it.second;

            if(count <= minCount){
                minCount = min(count,minCount);
                ans = city;
            }
        }
        return ans;     
    }
};