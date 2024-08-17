class Solution {
public:
    int f(int i, int target, vector<int> &nums, vector<vector<int>> &dp, int offset){
    if(i == -1){
        return target == 0 ? 1 : 0;
    }
    if(target + offset < 0 || target + offset >= dp[0].size()) return 0; // Check for out-of-bound access
    if(dp[i][target + offset] != -1) return dp[i][target + offset];
    int minus = f(i - 1, target + nums[i], nums, dp, offset);
    int plus = f(i - 1, target - nums[i], nums, dp, offset);
    return dp[i][target + offset] = minus + plus;
}

int findTargetSumWays(vector<int>& nums, int target) {
    int n = nums.size();
    int sum = accumulate(nums.begin(), nums.end(), 0);
    int offset = sum; // This is the maximum possible value of target + sum
    vector<vector<int>> dp(n, vector<int> (2 * sum + 1, -1));
    return f(n - 1, target, nums, dp, offset);
}

};