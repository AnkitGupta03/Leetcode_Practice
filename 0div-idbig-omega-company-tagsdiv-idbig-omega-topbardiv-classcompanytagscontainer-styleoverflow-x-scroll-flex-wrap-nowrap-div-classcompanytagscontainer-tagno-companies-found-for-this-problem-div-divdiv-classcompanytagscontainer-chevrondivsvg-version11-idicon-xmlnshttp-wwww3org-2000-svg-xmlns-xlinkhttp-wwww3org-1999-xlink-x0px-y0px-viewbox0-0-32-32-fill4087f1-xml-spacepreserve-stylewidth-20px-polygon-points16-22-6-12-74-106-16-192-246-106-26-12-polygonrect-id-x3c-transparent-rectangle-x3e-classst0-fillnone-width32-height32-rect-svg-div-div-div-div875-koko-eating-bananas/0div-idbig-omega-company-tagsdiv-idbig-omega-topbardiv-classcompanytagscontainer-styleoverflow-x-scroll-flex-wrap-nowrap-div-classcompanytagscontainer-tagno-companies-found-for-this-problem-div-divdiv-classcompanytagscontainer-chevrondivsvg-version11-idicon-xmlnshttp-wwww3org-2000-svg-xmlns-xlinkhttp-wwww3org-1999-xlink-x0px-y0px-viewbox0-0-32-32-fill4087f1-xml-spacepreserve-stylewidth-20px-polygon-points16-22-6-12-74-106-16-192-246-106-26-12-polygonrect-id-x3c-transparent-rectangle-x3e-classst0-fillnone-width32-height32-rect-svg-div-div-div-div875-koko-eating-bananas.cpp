class Solution {
public:
    bool check(vector<int> piles, int k, int h){
        int n = piles.size();
        long long sum = 0;
        for(int i=0; i<n; i++){
            sum += piles[i]/k;
            if(piles[i]%k != 0) sum++;
        }
        return sum <= h;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 0, r = 1e9;
        while((l+1) < r){
            int m = (l+r) / 2;
            if(check(piles, m, h)) r = m;
            else l = m;
        }
        return r;
    }
};