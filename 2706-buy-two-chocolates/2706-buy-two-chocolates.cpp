class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(), prices.end());
        int sum = prices[0] + prices[1];
        int leftover = money - sum;
        if(leftover >= 0) return leftover;
        return money;
    }
};