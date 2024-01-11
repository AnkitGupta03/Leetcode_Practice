class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int count1 = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    count1++;
                }
            }
        }
        
        queue<pair<int, int>> q;
        vector<vector<bool>> vis(m, vector<bool> (n, 0));
        int count = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0 || i==m-1 || j==0 || j==n-1){
                    if(grid[i][j] == 1){
                        q.push({i, j});
                        vis[i][j] = 1;
                        count++;
                    }
                }
            }
        }
        
        vector<int> dir = {-1, 0, 1, 0, -1};
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i=0; i<4; i++){
                int nr = r + dir[i];
                int nc = c + dir[i+1];
                if(nr >= 0 && nr < m && nc >= 0 && nc < n){
                    if(!vis[nr][nc] && grid[nr][nc] == 1){
                        q.push({nr, nc});
                        count++;
                        vis[nr][nc] = 1;
                    }
                }
            }
        }
        int ans = count1 - count;
        return ans;
    }
};