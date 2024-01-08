class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int fresh = 0;
        queue<pair<int, int>> q;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 2) q.push({i, j});
                if(grid[i][j] == 1) fresh++;
            }
        }
        
        vector<int> dir = {-1, 0, 1, 0, -1};
        int time = -1;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                
                for(int i=0; i<4; i++){
                    int nr = r + dir[i];
                    int nc = c + dir[i+1];
                    if(nr >= 0 && nr < m && nc >= 0 && nc < n){
                        if(grid[nr][nc] == 1){
                            q.push({nr, nc});
                            grid[nr][nc] = 2;
                            fresh--;
                        }
                    }
                }
            }
            time++;
        }
        if(fresh > 0) return -1;
        if(time == -1) return 0;     // in case there were no oranges initially.
        return time;
    }
};