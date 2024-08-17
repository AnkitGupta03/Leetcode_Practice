class Solution {
public:
    int f(int i, int target, vector<int> &nums, vector<vector<int>> &dp){
        if(i==-1){
            if(target == 0) return 1;
            else return 0;
        }
        if(dp[i][target+2000] != -1) return dp[i][target+2000];
        int minus = f(i-1, target + nums[i], nums, dp);
        int plus = f(i-1, target - nums[i], nums, dp);
        return dp[i][target+2000] = minus + plus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (4001, -1));
        return f(n-1, target, nums, dp);
    }
};