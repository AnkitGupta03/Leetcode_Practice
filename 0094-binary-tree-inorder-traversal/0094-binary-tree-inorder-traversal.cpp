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
    vector<int> inorderTraversal(TreeNode* root) { //iterative implementation using stack
        vector <int> v;
        stack <TreeNode* > s;
        while(root != NULL || !s.empty()){
            if(root != NULL){
                s.push(root);
                root = root -> left;
            }
            else{
                root = s.top();
                s.pop();
                v.push_back(root -> val);
                root = root -> right;
            }
        }
        return v;
    }
};