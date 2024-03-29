class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<pair<int, int>>> adj(n+1);
        for(auto it: times){
            adj[it[0]].push_back({it[1], it[2]});
        }
        
        vector<int> dist (n+1, 1e9);
        dist[k] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({dist[k], k});
        
        while(!q.empty()){
            auto it = q.top();
            q.pop();
            int node = it.second;
            int cost = it.first;
            
            for(auto i: adj[node]){
                int adjNode = i.first;
                int edW = i.second;
                
                if(edW + cost < dist[adjNode]){
                    dist[adjNode] = edW + cost;
                    q.push({dist[adjNode], adjNode});
                }
            }
        }
        
        for(int i=1; i<dist.size(); i++){
            if(dist[i] == 1e9){
                return -1;
            }
        }
        
        int ans = *max_element(dist.begin()+1, dist.end());
        return ans;
    }
};