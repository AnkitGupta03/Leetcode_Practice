class Solution {
public:
    int characterReplacement(string s, int k) {
        //not fully understood.
        vector<int> count(26);
        int n = s.length();
        int i = 0;
        int maxf = 0;
        
        for(int j=0; j<n; j++){
            count[s[j] - 'A']++;
            maxf = max(maxf, count[s[j] - 'A']);
            if(j-i+1 > maxf+k){
                count[s[i] - 'A']--;
                i++;
            }
            
        }
        return n-i;
    }
};