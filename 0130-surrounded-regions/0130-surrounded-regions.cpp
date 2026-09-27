class Solution {
public:
    void bfs(int r,int c,vector<vector<int>>&vis,vector<vector<char>>&board){
        int n = board.size();
        int m = board[0].size();
        vis[r][c] = 1;
        board[r][c] = 'S';
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
                if(newx>=0 && newx<n && newy>=0 && newy<m && !vis[newx][newy] && board[newx][newy] == 'O'){
                    vis[newx][newy] =1;
                    board[newx][newy] = 'S';
                    q.push({newx,newy});
                }
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));

        for(int j=0;j<m;j++){
            if(!vis[0][j] && board[0][j] == 'O'){
                bfs(0,j,vis,board);
            }
        }

        for(int j=0;j<m;j++){
            if(!vis[n-1][j] && board[n-1][j] == 'O'){
                bfs(n-1,j,vis,board);
            }
        }

        for(int i=0;i<n;i++){
            if(!vis[i][0] && board[i][0] == 'O'){
                bfs(i,0,vis,board);
            }
        }

        for(int i=0;i<n;i++){
            if(!vis[i][m-1] && board[i][m-1] == 'O'){
                bfs(i,m-1,vis,board);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == 'S'){
                    board[i][j] = 'O';
                }else if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
};