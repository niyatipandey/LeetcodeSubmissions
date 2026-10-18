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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map<string,int>mpp;

        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail = accounts[i][j];
                if(mpp.find(mail) == mpp.end()){
                    mpp[mail] = i;
                }
                else{
                    ds.unionBySize(mpp[mail] , i);
                }
            }
        }

        vector<string>mergedMails[n];
        for(auto it : mpp){
            string mail = it.first;
            int node = ds.findParent(it.second);

            mergedMails[node].push_back(mail);
        }

        vector<vector<string>>ans;

        for(int i=0;i<n;i++){
            if(mergedMails[i].size() == 0){
                continue;
            }
            sort(mergedMails[i].begin(),mergedMails[i].end());
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for(auto it : mergedMails[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};