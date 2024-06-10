class Solution {
public:
    int maxTotalReward(vector<int>& rewardValues) {
        sort(rewardValues.begin(), rewardValues.end());
        const int S = 100100;
        bitset<S> b;
        b[0] = 1;
        bitset<S> m;
        int p = 0;
        for (int x : rewardValues) {
            while (p < x) 
                m.set(p++);
            b |= (b & m) << x;
        }
        int r = b.size() - 1;
        while (!b[r]) r--;
        return r;
    }
};