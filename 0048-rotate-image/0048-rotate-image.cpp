class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // optimised approach, in place.
        // first we will transpose the matrix.
        int n = matrix.size();
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        //now we will reverse every row i.e. mat[i], which will give us the clockwise rotated matrix.
        for(int i=0; i<n; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};