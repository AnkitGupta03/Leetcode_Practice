class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.length() - 1;
        
        while(l < r){
            if(!isalnum(s[l]))
                l++;
            else if(!isalnum(s[r]))  // you have to write 'else if' and not 'if', because if there are two non alphanumeric characters consecutively, then it goes to the condition tolower(s[l]) != tolower(s[r]) and returns false, even though the answer would be true.
                r--;  //due to else if only one condition statement gets executed in one loop. So, until and unless l becomes alnum loop runs, then until r becomes alnum loop runs, and then it gets checked whether the both characters are same or not.
            else if(tolower(s[l]) != tolower(s[r]))
                return false;
            else{
                l++;
                r--;
            }
        }
        return true;
        
    }
};