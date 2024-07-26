class Solution {
public:
    int helper(vector<int> &nums, int i, vector<int> &dp){
        if(i==0) return dp[i] = nums[0];
        if(i==1) return dp[i] = max(nums[0], nums[1]);
        if(dp[i] != -1) return dp[i];
        return dp[i] = max(helper(nums, i-1, dp), helper(nums, i-2, dp) + nums[i]);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return helper(nums, n-1, dp);
    }
};