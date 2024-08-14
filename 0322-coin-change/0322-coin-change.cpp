class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX); // INT_MAX because we are finding minimum value
        // base case;
        dp[0] = 0;
        // transition, we are filling the table from amount = 0, amount = amount;
        for(int i=1; i<=amount; i++){
            int min_value = INT_MAX;
            for(int j=0; j<coins.size(); j++){
                if(i - coins[j] >= 0)
                min_value = min(min_value, dp[i - coins[j]]);
            }
            // trying to find the minimum number of coins for a given amount i
            if(min_value != INT_MAX) dp[i] = min_value + 1; // if min_value == INT_MAX, it means we are not able to find a valid number of coins to get to that amount, so no need to update it , leave it as INT_MAX,  which won't interfere with calculations of minimum value.
        }
        //final subproblem
        if(dp[amount] == INT_MAX) return -1;    // now after whole calculation if dp[amount] == INT_MAX, then it means it is not possible to get to that amount, so return -1;
        return dp[amount];  
    }
};