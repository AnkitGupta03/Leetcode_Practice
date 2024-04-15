class DisjointSet {
    vector<int> rank, parent;
public:
    DisjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        for(int i=0; i<n; i++){
            parent[i] = i;
        }
    }
    
    int findUPar(int node){
        if(parent[node] == node) return node;
        return parent[node] = findUPar(parent[node]);
    }
    
    void unionByRank(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        
        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size(); // n = number of vertices
        
        vector<pair<int, int>> edges;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(isConnected[i][j] == 1){             // list of edges in the graph.
                    edges.push_back({i, j});
                }
            }
        }
        
        int count = 0;
        DisjointSet ds(n);
        for(auto it: edges){
            int u = it.first;
            int v = it.second;
            
            ds.unionByRank(u, v);
        }
        
        for(int i=0; i<n ;i++){
            if(ds.findUPar(i) == i) count++;
        }
        return count;
    }
};