class Solution {
public:
    bool dfs(int node,vector<int>&vis,vector<int>&pathVis,vector<vector<int>>&graph,vector<int>&check){
        vis[node] = 1;
        pathVis[node] =1;

        for(auto it : graph[node]){
            if(!vis[it]){
                if(dfs(it,vis,pathVis,graph,check) == true){
                    return true;
                }
            }else if(pathVis[it]){
                return true;
            }
        }

        check[node] = 1;
        pathVis[node] =0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>vis(n,0);
        vector<int>pathVis(n,0);
        vector<int>check(n,0);
        vector<int>ans;

        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(dfs(i,vis,pathVis,graph,check) == true){
                    continue;
                }
            }
        }

        for(int i=0;i<n;i++){
            if(check[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};