class Solution {
public:
    void bfs(int row, int col, vector<vector<bool>> &vis, vector<vector<char>> &grid){
        int m = grid.size();
        int n = grid[0].size();
        
        queue<pair<int, int>> q;
        q.push({row, col});
        vis[row][col] = 1;
        
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            
            for(auto dir: directions){
                int nr = r + dir.first;
                int nc = c + dir.second;
                if(nr >=0 && nr < m && nc >= 0 && nc < n){
                    if(grid[nr][nc] == '1' && !vis[nr][nc]){
                        vis[nr][nc] = 1;
                        q.push({nr, nc});
                    }
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<bool>> vis(m, vector<bool> (n, 0));
        int count = 0;
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    count++;
                    bfs(i, j, vis, grid);
                }
            }
        }
        return count;
    }
};