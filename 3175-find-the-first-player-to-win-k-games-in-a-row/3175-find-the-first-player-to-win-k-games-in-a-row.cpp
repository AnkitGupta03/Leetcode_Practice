class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int n = skills.size();
        int maxi = *max_element(skills.begin(), skills.end());
        unordered_map<int, int> mpp;
        for(int i=0; i<skills.size(); i++){
            mpp[skills[i]] = i;
        }
        if(k > n) return mpp[maxi];
        int x = 0;
        int i = 0;
        int j = i+1;
        while(x < k){
            if(skills[i] > skills[j]){
                skills.push_back(skills[j]);
                x++;
                j++;
                
            }
            else{
                skills.push_back(skills[i]);
                x = 1;
                i = j;
                j = i+1;
            }
        }
        return mpp[skills[i]];
    }
};