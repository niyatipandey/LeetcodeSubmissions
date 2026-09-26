class Solution {
public:
    void dfs(int node,vector<int>&vis,int n,vector<vector<int>>&isConnected){
        vis[node]=1;

        for(int i=0;i<n;i++){
            if(!vis[i] && isConnected[node][i]){
                dfs(i,vis,n,isConnected);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int>vis(n+1,0);
        int count =0;

        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,vis,n,isConnected);
                count++;
            }
        }
        return count;
    }
};