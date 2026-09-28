class Solution {
public:
    void bfs(int r,int c,vector<vector<int>>&vis,vector<vector<int>>&grid){
        int n = grid.size();
        int m = grid[0].size();
        grid[r][c] = -1;

        int dr[4] = {1,0,-1,0};
        int dc[4] = {0,1,0,-1};

        queue<pair<int,int>>q;
        q.push({r,c});
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int newx = x + dr[i];
                int newy = y + dc[i];
                while(newx >=0 && newx <n && newy>=0 && newy <m && !vis[newx][newy] && grid[newx][newy] == 1){
                    grid[newx][newy] = -1;
                    vis[newx][newy] = 1;
                    q.push({newx,newy});
                }
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            if(!vis[i][0] && grid[i][0] == 1){
                bfs(i,0,vis,grid);
            }
        }

        for(int i=0;i<n;i++){
            if(!vis[i][m-1] && grid[i][m-1] == 1){
                bfs(i,m-1,vis,grid);
            }
        }

        for(int i=0;i<m;i++){
            if(!vis[0][i] && grid[0][i] == 1){
                bfs(0,i,vis,grid);
            }
        }

        for(int i=0;i<m;i++){
            if(!vis[n-1][i] && grid[n-1][i] == 1){
                bfs(n-1,i,vis,grid);
            }
        }

        int count =0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    count++;
                }
            }
        }
        return count;
    }
};