/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        
        //case 1 where the root is one of p or q, then we return the root.
        if(root -> val == p -> val || root -> val == q -> val)
            return root;
        //Now we will traverse through left and right subtree.
        TreeNode *lca1 = lowestCommonAncestor(root -> left, p, q);
        TreeNode *lca2 = lowestCommonAncestor(root -> right, p, q);
        
        // case 2 where the p belongs to left subtree and q belongs to right subtree, then we return the root.
        if(lca1 != NULL && lca2!= NULL)
            return root;
        // case 3 where both p and q are in left subtree, then we return lca1;
        if(lca1 != NULL)
            return lca1;
        else        // case 4 where p&q both are in right subtree, or both are not even in right subtree, then we return lca2, which will return sth if it contains both, or NULL if contains none.
            return lca2;
    }
};