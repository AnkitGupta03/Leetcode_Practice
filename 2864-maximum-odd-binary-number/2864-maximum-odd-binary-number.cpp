class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.length();
        int count = 0;
        for(int i=0; i<s.length(); i++){
            if(s[i] == '1'){
                count++;
            }
        }
        
        for(int i=0; i<count-1; i++){
            s[i] = '1';
        }
        for(int i = count-1; i<s.size()-1; i++){
            s[i] = '0';
        }
        s[n-1] = '1';
        
        return s;
    }
};