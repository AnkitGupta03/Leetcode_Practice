class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size();
        int n = img[0].size();
        vector<vector<int>> ans = img;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int avgsum = img[i][j];
                int cnt = 1;
                int dx[] = {-1, -1, -1,  0, 0,  1, 1, 1};
                int dy[] = {-1,  0,  1, -1, 1, -1, 0, 1};

                for(int k = 0; k < 8; k++) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];

                    if(ni >= 0 && ni < m && nj >= 0 && nj < n) {
                        avgsum += img[ni][nj];
                        cnt++;
                    } else {
                        continue;
                    }
                }
                int avg = avgsum/cnt;
                ans[i][j] = avg;
            }
        }
        return ans;
    }
};