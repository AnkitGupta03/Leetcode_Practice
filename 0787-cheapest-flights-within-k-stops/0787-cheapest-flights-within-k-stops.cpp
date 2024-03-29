#include<bits/stdc++.h>
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int m = flights.size();     // no of edges
        vector<vector<pair<int, int>>> adj(n);
        for(int i=0; i<flights.size(); i++){
            adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }
        vector<int> dist(n, 1e9);
        queue<pair<int, pair<int, int>>> q;
        dist[src] = 0;
        q.push({0, {src, 0}});
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node= it.second.first;
            int cost= it.second.second;
            
            if(stops > k) continue;
            for(auto i: adj[node]){
                int adjNode = i.first;
                int edW = i.second;
                
                if(cost + edW < dist[adjNode]){
                    dist[adjNode] = cost + edW;
                    q.push({stops+1, {adjNode, dist[adjNode]}});
                }
            }
        }
        if(dist[dst] == 1e9) return -1;
        return dist[dst];
    }
};