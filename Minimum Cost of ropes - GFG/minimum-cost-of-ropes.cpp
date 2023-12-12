//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        multiset<long long> ms;
        for(int i=0; i<n; i++){
            ms.insert(arr[i]);
        }
        long long ans = 0;
        while(ms.size() > 1){
            auto it = ms.begin();
            long long cost = *it;
            ms.erase(it);
            it = ms.begin();
            cost += *it;
            ms.erase(it);
            ms.insert(cost);
            ans += cost;
        }
        return ans;
        //code here
    }
};


//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends