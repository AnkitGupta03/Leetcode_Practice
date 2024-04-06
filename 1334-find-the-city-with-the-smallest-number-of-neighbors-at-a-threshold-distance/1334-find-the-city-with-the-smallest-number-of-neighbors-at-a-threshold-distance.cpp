class Solution {
public:
    
    static bool compare(pair<int, int> p1, pair<int, int> p2){
        if(p1.first == p2.first) return p1.second > p2.second;
        return p1.first<p2.first;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> adjMatrix(n, (vector<int> (n, 1e9)));
        for(auto i: edges){
            int u = i[0];
            int v = i[1];
            int wt = i[2];
            
            adjMatrix[u][v] = wt;
            adjMatrix[v][u] = wt;
        }
        
        for(int i=0; i<n; i++){
            adjMatrix[i][i] = 0;
        }
        
        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    adjMatrix[i][j] = min(adjMatrix[i][j], (adjMatrix[i][k] + adjMatrix[k][j]));
                }
            }
        }
        
        vector<pair<int, int>> ans;
        for(int i=0; i<n; i++){
            int count = 0;
            for(int j=0; j<n; j++){
                if(adjMatrix[i][j] <= distanceThreshold) count++;
            }
            ans.push_back({count, i});
        }
        
        sort(ans.begin(), ans.end(), compare);

        int res = ans[0].second;
        return res;
    }
    
};