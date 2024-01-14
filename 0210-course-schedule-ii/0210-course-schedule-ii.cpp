class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adj(n);
        
        for(int i=0; i<prerequisites.size(); i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
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
        
        int count = 0;
        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            count++;
            topo.push_back(node);
            
            for(auto i: adj[node]){
                indegree[i]--;
                if(indegree[i] == 0){
                    q.push(i);
                }
            }
        }
        if(count == n) return topo;
        return {};
    }
};