class Solution {
public:
    bool differByone(string &s1, string &s2){
        int count = 0;
        for(int i=0; i<s1.length(); i++){
            if(s1[i] != s2[i]){
                count++;
            }
            if(count > 1) return false;
        }
        return (count == 1);
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        if(find(wordList.begin(), wordList.end(), endWord) == wordList.end()){
            return 0;
        }
        
        int n = wordList.size();
        unordered_map<string, int> wlIndex;
        wlIndex[beginWord] = 0;
        for(int i=0; i<wordList.size(); i++){
            if(wordList[i] != beginWord) wlIndex[wordList[i]] = i+1;
        }
        vector<vector<int>> adj(n+1);
        for(int i=0; i<n; i++){
            if(differByone(beginWord, wordList[i])){
                int u = wlIndex[beginWord];
                int v = wlIndex[wordList[i]];
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(differByone(wordList[i], wordList[j])){
                    int u = wlIndex[wordList[i]];
                    int v = wlIndex[wordList[j]];
                    adj[u].push_back(v);
                    adj[v].push_back(u);
                }
            }
        }
        
        queue<int> q;
        vector<int> dist(n+1, 1e9);
        q.push(0);
        dist[0] = 0;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto i: adj[node]){
                if((dist[node] + 1) < dist[i]){
                    dist[i] = dist[node] + 1;
                    q.push(i);
                }
            }
        }
        if(dist[wlIndex[endWord]] == 1e9){
            return 0;
        }
        return dist[wlIndex[endWord]] + 1;
    }
};