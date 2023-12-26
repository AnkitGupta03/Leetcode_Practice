class Solution {
public: // alternate way where I am using vector instead of set.
    bool isPathCrossing(string path) {
        int n = path.size();
        vector<pair<int, int>> map;
        map.push_back({0, 0});
        int x = 0, y = 0;
        for(int i = 0; i < n; i++){
            if(path[i] == 'N') y++;
            else if(path[i] == 'S') y--;
            else if(path[i] == 'E') x++;
            else if(path[i] == 'W') x--;

            if(find(map.begin(), map.end(), make_pair(x, y)) != map.end())
                return true;

            map.push_back({x, y});
        }
        return false;
    }
};
