/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<long long> level;
            for(int i=0; i<size; i++){
                TreeNode *node = q.front();
                q.pop();
                level.push_back(node -> val);
                if(node -> left) q.push(node -> left);
                if(node -> right) q.push(node -> right);
            }
            long long sum = accumulate(level.begin(), level.end(), 0LL);
            ans.push_back(sum);
        }
        sort(ans.begin(), ans.end(), greater<long long>());
        if(ans.size() < k) return -1;
        return ans[k-1];
    }
};