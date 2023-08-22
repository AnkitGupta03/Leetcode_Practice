class Solution {
public:
    void sortColors(vector<int>& nums) {
        //optimal solution using dutch national flag algorithm.
        int n = nums.size();
        int low = 0, mid = 0, high = n-1;
        while(mid <= high){
            if(nums[mid] == 0){
                swap(nums[mid], nums[low]);
                mid++;
                low++;
            }
            else if(nums[mid] == 1)
                mid++;
            else{
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};