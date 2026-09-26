class Solution {
public:
    int count = 0;
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int dr[4] = {1,0,-1,0};
        int dc[4] = {0,1,0,-1};
        int fresh =0;
        queue<pair<int,int>>q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }

        while(!q.empty() && fresh>0){
            int size = q.size();
            for(int i=0;i<size;i++){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                for(int i=0;i<4;i++){
                    int newx = x + dr[i];
                    int newy = y + dc[i];
                    if(newx >=0 && newx <n && newy >=0 && newy<m && grid[newx][newy] == 1){
                        grid[newx][newy] =2;
                        fresh--;
                        q.push({newx,newy});
                    }
                }
            }
            count++;
        }

        if(fresh > 0){
            return -1;
        }

        return count;
    }
};