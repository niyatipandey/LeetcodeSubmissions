class Solution {
public:
    bool check(int node,int n,vector<int>&color,vector<vector<int>>& graph){
        color[node] = 0;
        queue<int>q;
        q.push(node);

        while(!q.empty()){
            int x = q.front();
            q.pop();

            for(auto it : graph[x]){
                if(color[it] == -1){
                    color[it] = 1- color[x];
                    q.push(it);
                }else if(color[it] == color[x]){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n,-1);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(color[i] == -1){
                    if(check(i,n,color,graph) == false){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};