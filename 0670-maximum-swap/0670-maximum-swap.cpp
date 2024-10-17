class Solution {
public:
    int maximumSwap(int num) {
        string nums = to_string(num);
        int n= nums.length();
        string sorted = nums;
        sort(sorted.begin(), sorted.end());
        reverse(sorted.begin(), sorted.end());
        
        int index = -1;
        for(int i=0; i<n; i++){
            if(nums[i] != sorted[i]){
                index = i;
                break;
            }
        }
        if(index == -1) return num;
        
        int jndex;
        for(int j=index; j<n; j++){
            if(nums[j] == sorted[index]){
                jndex = j;
            }
        }
        
        swap(nums[index], nums[jndex]);
        int ans = stoi(nums);
        return ans;
    }
};