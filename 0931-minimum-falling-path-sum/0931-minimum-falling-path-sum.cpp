class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n));
        
        for(int i=0; i<n; i++){
            dp[n-1][i] = matrix[n-1][i];        // base case;
        }
        
        for(int i=n-2; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                if(j == n-1){
                    dp[i][j] = min(dp[i+1][j], dp[i+1][j-1]) + matrix[i][j];
                }
                else if(j == 0){
                    dp[i][j] = min(dp[i+1][j], dp[i+1][j+1]) + matrix[i][j];
                }
                else{
                    dp[i][j] = min({dp[i+1][j], dp[i+1][j-1], dp[i+1][j+1]}) + matrix[i][j];
                }
            }
        }
        int ans = *min_element(dp[0].begin(), dp[0].end());
        return ans;
    }
};