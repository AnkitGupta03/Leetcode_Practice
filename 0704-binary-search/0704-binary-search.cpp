class Solution {
public:
    int search(vector<int>& nums, int x) {
        int l = 0, h = nums.size() - 1;
        
        while(l<=h){
            int mid = (l+h)/2;
            if(x == nums[mid])
                return mid;
            else if(x > nums[mid])
                l = mid + 1;
            else
                h = mid - 1;
        }
        return -1;
    }
};