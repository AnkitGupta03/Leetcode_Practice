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
    vector<int> postorderTraversal(TreeNode* root) {
        //morris postorder traversal.
        vector<int> res;
    TreeNode* current = root;
    while (current != NULL) {
        if (current->right == NULL) {
            res.push_back (current->val);
            current = current->left;
        } else {
            TreeNode* predecessor = current->right;
            while (predecessor->left != NULL && predecessor->left != current) {
                predecessor = predecessor->left;
            }
            if (predecessor->left == NULL) {
                res.push_back (current->val);
                predecessor->left = current;
                current = current->right;
            } else {
                predecessor->left = NULL;
                current = current->left;
            }
        }
    }
    reverse (res.begin (), res.end ());
    return res;
    }
};