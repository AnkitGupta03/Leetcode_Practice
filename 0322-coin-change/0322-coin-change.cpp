class Solution {
public:
    int f(int amount, vector<int> &coins, vector<int> &dp){
        if(amount == 0) return 0; // because for f(0), it will take 0 number of coins to get to amount = 0;
        if(amount < 0) return INT_MAX;  // if the amount required goes to negative, it means it is not possible to get to that amount with any number of coins, so, to never consider this case, i have made it to INT_MAX so this case won't be considered ever while calculating minimum number of coins.
        if(dp[amount] != -1e5) return dp[amount];   // checking if already calculated
        int min_value = INT_MAX;
        for(int i=0; i<coins.size(); i++){
            if(f(amount - coins[i], coins, dp) >= 0) // we are putting this check because, if f(amount - coins[i], coins, dp) == -1, then it means that it is not possible to get that amount, but in calculation it becomes the minimum most value, which is wrong logically, so we put this check to avoid this inconsistency.
            min_value = min(min_value, f(amount - coins[i], coins, dp)); // here we are finding the minimum number of coins taken if we consider the first coin, second coin, third coin, basically all the choices that are available at every step;
        }
        
        if(min_value == INT_MAX) return dp[amount] = -1; // now if the minimum number of coins after considering all the possible cases come to be infinite, it means it is not possible to get to that amount by using the given coins, so we return -1;
        return  dp[amount] = min_value + 1; // if we get some valid min_value, then we add one to it, to make it the total number of coins required considering the current coin also.
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1e5); // why initial value == -1e5 ? generally, we keep the initial value to be -1, but here -1 has some predefined meaning acc. to the question, so we assign the initial value to be a value, which is never used during calculations in this question.
        return f(amount, coins, dp);
    }
};