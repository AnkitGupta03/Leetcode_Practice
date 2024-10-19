class Solution {
public:
    string invert_and_reverse(string s){
        int n = s.length();
        for(int i=0; i<n; i++){
            if(s[i] == '0') s[i] = '1';
            else s[i] = '0';
        }
        for(int i=0; i<n/2; i++){
            swap(s[i], s[n-i-1]);
        }
        return s;
    }
    
    string recursion(int n){
        if(n == 1) return "0";
        string before = recursion(n-1);
        string after = invert_and_reverse(before);
        string ans = before+"1"+after;
        return ans;
    }
    
    char findKthBit(int n, int k) {
        string res = recursion(n);
        return res[k-1];
    }
};