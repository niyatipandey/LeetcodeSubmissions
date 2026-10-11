class Solution {
public:
    int bfs(int i,int j,vector<vector<int>>&vis,vector<vector<int>>&grid,int n){
        queue<tuple<int,int,int>>q;
        q.push({i,j,1});
        vis[i][j] = 1;
        int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dc[] = {-1,  0,  1, -1, 1, -1, 0, 1};

        while(!q.empty()){
            auto [row,col,dist] = q.front();
            q.pop();

            if(row == n-1 && col == n-1){
                return dist;
            }

            for(int i=0;i<8;i++){
                int newr = row + dr[i];
                int newc = col + dc[i];
                if(newr>=0 && newr<n && newc>=0 && newc <n && !vis[newr][newc] && grid[newr][newc] == 0){
                    vis[newr][newc] = 1;
                    q.push({newr,newc,dist+1});
                }
            }
        }
        return -1;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>>vis(n,vector<int>(n,0));

        if(grid[0][0] == 1 || grid[n-1][n-1] == 1){
            return -1;
        }
        return bfs(0,0,vis,grid,n);
    }
};