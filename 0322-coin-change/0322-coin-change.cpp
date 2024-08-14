class Solution {
public:
    int f(int amount, vector<int> &coins, vector<int> &dp){
        if(amount == 0) return 0;
        if(amount < 0) return INT_MAX;
        if(dp[amount] != -1e5) return dp[amount];
        int min_value = INT_MAX;
        for(int i=0; i<coins.size(); i++){
            if(f(amount - coins[i], coins, dp) >= 0)
            min_value = min(min_value, f(amount - coins[i], coins, dp));
        }
        if(min_value == INT_MAX) return dp[amount] = -1;
        return  dp[amount] = min_value + 1;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1e5);
        return f(amount, coins, dp);
    }
};