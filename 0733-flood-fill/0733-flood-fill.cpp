class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int x = image[sr][sc];
        int m = image.size();
        int n = image[0].size();
        
        vector<vector<bool>> vis(m, vector<bool> (n, 0));
        queue<pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;
        vis[sr][sc] = 1;
        
        vector<int> dir = {-1, 0, 1, 0, -1};
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            
            for(int i=0; i<4; i++){
                int nr = r + dir[i];
                int nc = c + dir[i+1];
                if(nr >= 0 && nr < m && nc >= 0 && nc < n){
                    if(image[nr][nc] == x && !vis[nr][nc]){
                        q.push({nr, nc});
                        image[nr][nc] = color;
                        vis[nr][nc] = 1;
                    }
                }
            }
        }
        return image;
    }
};