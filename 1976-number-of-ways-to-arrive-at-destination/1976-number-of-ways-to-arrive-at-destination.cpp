class Solution {
public:
    int mod = 1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto i: roads){
            adj[i[0]].push_back({i[1], i[2]});
            adj[i[1]].push_back({i[0], i[2]});
        }
        
        vector<long long> dist(n, 1e18), count(n, 0);
        dist[0] = 0;
        count[0] = 1;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({dist[0], 0});
        
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            long long cost = it.first;
            int node = it.second;
            
            if(cost > dist[node]) continue; // If this path is not the shortest, ignore it.
            
            for(auto i: adj[node]){
                int adjNode = i.first;
                long long edW = i.second;
                
                if(cost + edW < dist[adjNode]) {
                    dist[adjNode] = cost + edW;
                    count[adjNode] = count[node]; // Copy the count from the current node.
                    pq.push({dist[adjNode], adjNode});
                } else if(cost + edW == dist[adjNode]) {
                    count[adjNode] = (count[adjNode] + count[node]) % mod; // Add the count from the current node.
                }
            }
        }
        return count[n-1];
    }
};
