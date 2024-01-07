class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size(); // n = number of vertices
        
        vector<vector<int>> adjlist(n);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(isConnected[i][j] == 1){             // adjacency list of the graph.
                    adjlist[i].push_back(j);
                    adjlist[j].push_back(i);
                }
            }
        }
        
        int count = 0;
        queue<int> q;
        vector<bool> vis(n, 0);
        for(int i=0; i<n; i++){
            if(!vis[i]){
                q.push(i);
                count++;
                vis[i] = 1;
                while(!q.empty()){                  // running a bfs on the graph.
                    int node = q.front();
                    q.pop();
                    for(auto i: adjlist[node]){
                        if(!vis[i]){
                        vis[i] = 1;
                        q.push(i);
                    }   
                }
            }
            }
        }
        return count;
    }
};