class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        queue<pair<int, int>> q;
        vector<vector<bool>> vis(m, vector<bool> (n, 0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j] == 0){
                    q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }
        int distance = 0;
        vector<int> dir = {-1, 0, 1, 0, -1};
        while(!q.empty()){
            int sz = q.size();
            distance++;
            while(sz--){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                for(int i=0; i<4; i++){
                    int nr = r + dir[i];
                    int nc = c + dir[i+1];
                    if(nr >= 0 && nr < m && nc >= 0 && nc < n){
                        if(!vis[nr][nc]){
                            mat[nr][nc] = distance;
                            q.push({nr, nc});
                            vis[nr][nc] = 1;
                        }
                    }
                }
            }
        }
        return mat;
    }
};
