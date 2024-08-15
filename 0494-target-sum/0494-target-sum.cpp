class Solution {
public:
    int f(int i, int target, vector<int> &nums){
        if(i==-1){
            if(target == 0) return 1;
            else return 0;
        }
        int minus = f(i-1, target + nums[i], nums);
        int plus = f(i-1, target - nums[i], nums);
        return minus + plus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return f(n-1, target, nums);
    }
};