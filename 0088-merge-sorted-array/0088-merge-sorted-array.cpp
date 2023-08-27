class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
     vector<int> nums3;
     int a = 0, b = 0;
        while(a!=m && b!=n){
            if(nums1[a] < nums2[b]){
                nums3.push_back(nums1[a]);
                a++;
            }
            else if(nums2[b] < nums1[a]){
                nums3.push_back(nums2[b]);
                b++;
            }
            else{
                nums3.push_back(nums1[a]);
                nums3.push_back(nums2[b]);
                a++;
                b++;
            }
            
        }
        if(a==m){
            for(int i=b; i<n; i++){
                nums3.push_back(nums2[i]);
            }
        }
        else if(b == n){
            for(int i=a; i<m; i++){
                nums3.push_back(nums1[i]);
            }
        }
        
        for(int i=0; i< m+n; i++){
            nums1[i] = nums3[i];
        }
    }
};