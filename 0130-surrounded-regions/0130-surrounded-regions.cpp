class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        
        queue<pair<int, int>> q;
        vector<vector<bool>> vis(m, vector<bool> (n, 0));
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0 || j==0 || i==m-1 || j==n-1){       // traversing all boundary 'O's.
                    if(board[i][j] == 'O'){
                        q.push({i, j});
                        vis[i][j] = 1;
                        board[i][j] = '1';
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
                    if(nr >= 0 && nr < m  && nc >= 0 && nc < n){
                        if(!vis[nr][nc] && board[nr][nc] == 'O'){
                            board[nr][nc] = '1';
                            q.push({nr, nc});       
                            vis[nr][nc] = 1;
                        }
                    }
                }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == '1'){
                    board[i][j] = 'O';
                }
            }
        }
        
    }
};