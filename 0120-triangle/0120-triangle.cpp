class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<vector<int>> dp(m, vector<int> (m, 0));
        
        for(int j=m-1; j>=0; j--){
            dp[m-1][j] = triangle[m-1][j];      // base case.
        }
        
        for(int i=m-2; i>=0; i--){
            for(int j=0; j<=i; j++){
                dp[i][j] = min(dp[i+1][j], dp[i+1][j+1]) + triangle[i][j];
            }
        }
        return dp[0][0];
    }
};