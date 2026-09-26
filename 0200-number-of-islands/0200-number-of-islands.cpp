class Solution {
public:
    void bfs(int i,int j,vector<vector<int>>&vis,vector<vector<char>>&grid){
        int n = grid.size();
        int m = grid[0].size();
        vis[i][j] =1;
        int dr[4] = {1,0,-1,0};
        int dc[4] = {0,1,0,-1};

        queue<pair<int,int>>q;
        q.push({i,j});
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int newx = x + dr[i];
                int newy = y + dc[i];

                while(newx >= 0 && newx < n && newy>=0 && newy<m && grid[newx][newy] == '1' && !vis[newx][newy]){
                    vis[newx][newy]=1;
                    q.push({newx,newy});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int count =0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    bfs(i,j,vis,grid);
                    count++;
                }
            }
        }
        return count;
    }
};