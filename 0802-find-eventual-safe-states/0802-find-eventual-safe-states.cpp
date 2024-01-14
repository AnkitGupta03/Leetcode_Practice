class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();       // number of nodes.
        vector<vector<int>> adj(n);
        
        for(int i=0; i<n; i++){
            for(auto it: graph[i]){
                adj[it].push_back(i);
            }
        }
        
        vector<int> indegree(n);
        for(int i=0; i<n; i++){
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }
        
        queue<int> q;
        for(int i=0; i<n; i++){
            if(indegree[i] == 0) q.push(i);
        }
        
        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            
            for(auto i: adj[node]){
                indegree[i]--;
                if(indegree[i] == 0){
                    q.push(i);
                }
            }
        }
        sort(topo.begin(), topo.end());
        return topo;
    }
};