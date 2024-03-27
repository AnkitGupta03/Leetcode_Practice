class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        
        vector<vector<int>> efforts(m, vector<int> (n, 1e9));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;

        efforts[0][0] = 0;
        q.push({0, {0, 0}});
        
        vector<int> dir = {-1, 0, 1, 0, -1};
        vector<int> ansv;
        while(!q.empty()){
            auto it = q.top();
            q.pop();
            int diff = it.first;
            int r = it.second.first;
            int c = it.second.second;
            
            for(int i=0; i<4; i++){
                int nr = r + dir[i];
                int nc = c + dir[i+1];
                
                // if(r == m-1 && c == n-1) return diff;
                if(nr >=0 && nr < m && nc >= 0 && nc < n){
                    int newEffort = max(abs(heights[r][c] - heights[nr][nc]), diff);
                    if(newEffort < efforts[nr][nc]){
                        efforts[nr][nc] = newEffort;
                        q.push({newEffort, {nr, nc}});
                    }
                }
            }
        }
        return efforts[m-1][n-1];
    }
};