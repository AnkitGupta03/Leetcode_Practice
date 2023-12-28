class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalsum = 0;
        for(auto it: nums){
            totalsum += it;
        }
        if(totalsum%2 == 1) return false;
        int k = totalsum/2;
        
        vector<vector<bool>> dp(n+1, vector<bool> (k+1));
        for(int i=0; i<n ;i++){
            dp[i][0] = 1;
        }
        for(int i=1; i<=k; i++){
            dp[0][i] = 0;
        }
        
        for(int i=1; i<n; i++){
            for(int j=1; j<=k; j++){
                dp[i][j] = ((j-nums[i])>=0) ? (dp[i-1][j] || dp[i-1][j-nums[i]]) : (dp[i-1][j]);
            }
        }
        return dp[n-1][k];
    }
};