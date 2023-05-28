class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // optimal solution -> O(n) t.c.
        int min = INT_MAX;
        int maxProf = 0;
        
        for(int i=0; i<prices.size(); i++){
            int prof = prices[i] - min;
            if(prof > maxProf)
                maxProf = prof;
            if(prices[i] < min)
                min = prices[i];
        }
        return maxProf;
    }
};