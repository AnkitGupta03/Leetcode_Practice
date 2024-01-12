class Solution { // using dfs
public:
    bool dfscheck(int start, int col, vector<int> &color, vector<vector<int>> &adj){
        color[start] = col;
        
        for(auto it : adj[start]){
            if(color[it] == -1){
                if(!dfscheck(it, !col, color, adj)) return false;
            }
            else if(color[it] == col){
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        for(int i=0; i<n; i++){
            if(color[i] == -1){
                if(!dfscheck(i, 0, color, graph)) return false;
            }
        }
        return true;
    }
};