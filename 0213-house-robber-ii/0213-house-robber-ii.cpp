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
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);
        vector<int> dp1(n-1, -1);
        vector<int> dp2(n-1, -1);
        
        vector<int> v1(nums.begin(), nums.end()-1);
        vector<int> v2(nums.begin() + 1, nums.end());
        
        return max(helper(v1, n-2, dp1), helper(v2, n-2, dp2));
    }
};