class Solution {
public:
    bool dfscheck(int node, vector<bool> &vis, vector<bool> &pathvis, vector<bool> &check, vector<vector<int>> &adj){
        vis[node] = 1;
        pathvis[node] = 1;
        
        for(auto i: adj[node]){
            if(!vis[i]){
                if(dfscheck(i, vis, pathvis, check, adj)) return true;
            }
            else if(pathvis[i]){
                return true;
            }
        }
        
        check[node] = 1;
        pathvis[node] = 0;
        return false;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> vis(n, 0);
        vector<bool> pathvis(n, 0);
        vector<bool> check(n, 0);
        vector<int> safenodes;
        
        for(int i=0; i<n; i++){
            if(!vis[i]){
                dfscheck(i, vis, pathvis, check, graph);
            }
        }
        for(int i=0; i<n; i++){
            if(check[i]){
                safenodes.push_back(i);
            }
        }
        return safenodes;
    }
};