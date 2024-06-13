class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
        long long mod = 1e9 + 7;
        vector<vector<long long>> arr(k, vector<long long> (n, 0));
        for(int i=0; i<n; i++){
            arr[0][i] = (i+1) % mod;
        }
        for(int i=1; i<k; i++){
            arr[i][0] = 1;
        }
        for(int i=1; i<k; i++){
            for(int j=1; j<n; j++){
                arr[i][j] = (arr[i][j-1] + arr[i-1][j]) % mod;
            }
        }
        return arr[k-1][n-1];
    }
};
