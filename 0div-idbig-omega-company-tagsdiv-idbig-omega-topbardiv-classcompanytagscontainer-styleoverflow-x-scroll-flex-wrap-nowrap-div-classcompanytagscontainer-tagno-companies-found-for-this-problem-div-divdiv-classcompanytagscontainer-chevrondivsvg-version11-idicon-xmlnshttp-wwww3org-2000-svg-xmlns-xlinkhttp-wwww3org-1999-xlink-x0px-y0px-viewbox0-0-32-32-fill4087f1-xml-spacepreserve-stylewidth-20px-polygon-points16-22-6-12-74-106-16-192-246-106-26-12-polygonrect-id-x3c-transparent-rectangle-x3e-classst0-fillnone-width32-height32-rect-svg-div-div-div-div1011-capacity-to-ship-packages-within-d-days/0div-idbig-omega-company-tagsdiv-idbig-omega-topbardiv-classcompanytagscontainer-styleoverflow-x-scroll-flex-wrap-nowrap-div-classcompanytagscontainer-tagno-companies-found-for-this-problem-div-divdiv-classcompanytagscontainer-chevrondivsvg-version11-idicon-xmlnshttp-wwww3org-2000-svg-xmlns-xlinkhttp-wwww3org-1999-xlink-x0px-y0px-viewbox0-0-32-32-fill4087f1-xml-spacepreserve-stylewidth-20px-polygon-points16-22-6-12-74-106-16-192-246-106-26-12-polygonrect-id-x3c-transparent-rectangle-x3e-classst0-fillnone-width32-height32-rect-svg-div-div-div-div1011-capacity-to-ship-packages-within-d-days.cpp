class Solution {
public:
    bool check(vector<int> a, int k, int days){
        int n = a.size();
        int x = k;
        int count = 0;
        for(int i=0; i<n-1; i++){
             x -= a[i];
            if(x < a[i+1]){
                count++;
                x = k;
            }
        }
        count++;
        return count <= days;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int maxi = *max_element(weights.begin(), weights.end());
        int l = maxi-1, h = 1e9;
        while( l+1 < h ){
            int m = (l+h) / 2;
            if(check(weights, m, days)) h = m;
            else l = m;
        }
        return h;
    }
};