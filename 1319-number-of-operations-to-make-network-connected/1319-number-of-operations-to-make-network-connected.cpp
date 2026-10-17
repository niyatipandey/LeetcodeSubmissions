class DisjointSet{
    vector<int>parent;
    vector<int>size;
    public:
        DisjointSet(int n){
            parent.resize(n+1);
            size.resize(n+1);

            for(int i=0;i<n+1;i++){
                parent[i] = i;
                size[i] =1;
            }
        }

        int findParent(int node){
            if(node == parent[node]){
                return node;
            }
            return parent[node] = findParent(parent[node]);
        }
        void unionBySize(int u,int v){
            int pu = findParent(u);
            int pv = findParent(v);

            if(pu == pv){
                return;
            }
            else if(size[pu] > size[pv]){
                parent[pv] = pu;
                size[pu] += size[pv];
            }else{
                parent[pu] = pv;
                size[pv] += size[pu];
            }
        }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1){
            return -1;
        }
        vector<vector<int>>adj(n);

        for(auto it : connections){
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }


        DisjointSet ds(n);

        for(int i=0;i<n;i++){
            for(auto x : adj[i]){
                if(ds.findParent(i) != ds.findParent(x)){
                    ds.unionBySize(i,x);
                }
            }
        }
        int count =0;

        for(int i=0;i<n;i++){
            if(ds.findParent(i) == i){
                count++;
            }
        }
        return count-1;

    }
};