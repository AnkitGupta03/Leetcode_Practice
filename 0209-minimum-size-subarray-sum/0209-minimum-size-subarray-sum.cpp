class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;
        int minLength = 1e6;
        int currsum = 0;
        while(j < n){
            currsum += nums[j];
            
            while(currsum >= target){
                int currLength = j-i+1;
                minLength = min(minLength, currLength);
                currsum -= nums[i];
                i++;
            }
            
            j++;
        }
        
        if(minLength == 1e6) return 0;
        return minLength;
    }
};