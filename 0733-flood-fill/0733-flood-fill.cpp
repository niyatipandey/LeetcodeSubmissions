class Solution {
public:
    void bfs(int sr,int sc,vector<vector<int>>&image,int color,int oldColor){
        int n = image.size();
        int m = image[0].size();
        image[sr][sc] = color;
        int dr[4]= {1,0,-1,0};
        int dc[4] = {0,1,0,-1};
        queue<pair<int,int>>q;
        q.push({sr,sc});

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int newx = x + dr[i];
                int newy = y + dc[i];
                if(newx >=0 && newx<n && newy >=0 && newy<m && image[newx][newy] == oldColor){
                    image[newx][newy] = color;
                    q.push({newx,newy});
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldColor = image[sr][sc];
        if(oldColor == color){
            return image;
        }
        bfs(sr,sc,image,color,oldColor);
        return image;
    }
};