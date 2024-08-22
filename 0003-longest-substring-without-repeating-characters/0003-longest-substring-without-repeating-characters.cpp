class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        vector<int> hash(256, -1);
        int l = 0, r = 0, maxlength = 0;
        while(r < n){
            if(hash[s[r]] != -1){
                if(hash[s[r]] >= l){
                    l = hash[s[r]] + 1;
                }
            }
            int length = r-l+1;
            maxlength = max(maxlength, length);
            hash[s[r]] = r;
            r++;
        }
        return maxlength;
    }
};