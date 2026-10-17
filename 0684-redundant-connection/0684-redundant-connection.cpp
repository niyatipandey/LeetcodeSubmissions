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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DisjointSet ds(n);

        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];

            if(ds.findParent(u) == ds.findParent(v)){
                return {u,v};
            }else{
                ds.unionBySize(u,v);
            }
        }
        return {-1,-1};
    }
};