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
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DisjointSet ds(n);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j] == 1){
                    if(ds.findParent(i) != ds.findParent(j)){
                        ds.unionBySize(i,j);
                    }
                }
            }
        }
        int count =0;

        for(int i=0;i<n;i++){
            if(ds.findParent(i) == i){
                count++;
            }
        }
        return count;


    }
};