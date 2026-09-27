class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        queue<pair<int,int>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<vector<int>>dis(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == 0){
                    q.push({i,j});
                    vis[i][j] =1;
                    dis[i][j] =0;
                }
            }
        }

        int dr[4] = {1,0,-1,0};
        int dc[4] = {0,1,0,-1};

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int newx = x + dr[i];
                int newy = y + dc[i];
                if(newx>=0 && newx < n && newy >=0 && newy < m && !vis[newx][newy]){
                    dis[newx][newy] = dis[x][y] +1;
                    vis[newx][newy] =1;
                    q.push({newx,newy});
                }
            }
        }
        return dis;
    }
};