class Solution {
public:
    int f(int amount, vector<int> &coins, int index, vector<vector<int>> &dp){
        if(amount == 0) return 1;
        if(amount < 0) return 0;
        if(dp[index][amount] != -1) return dp[index][amount];
        int count = 0;
        for(int j=index; j<coins.size(); j++){
            count += f(amount - coins[j], coins, j, dp);
        }
        return dp[index][amount] = count;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount + 1, -1));
        return f(amount, coins, 0, dp);
    }
};