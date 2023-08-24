class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // brute force approach, not in place, as the question suggests.
        int n = matrix.size();
        vector<vector<int>> a(n, vector<int>(n));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                a[j][n-i-1] = matrix[i][j];
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                matrix[i][j] = a[i][j];
            }
        }
    }
};