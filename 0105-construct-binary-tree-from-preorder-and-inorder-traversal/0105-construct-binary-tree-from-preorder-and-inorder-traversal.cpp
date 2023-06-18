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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        map<int, int> inMap;
        for(int i=0; i<inorder.size(); i++){
            inMap[inorder[i]] = i;
        }
        TreeNode *root = cTree(preorder, inorder, 0, n-1, inMap);
        
        return root;
    }
    
    int preIndex = 0;
    TreeNode* cTree(vector<int>&preorder, vector<int>& inorder, int is, int ie, map<int, int>& inMap){
        
        if(is > ie) return NULL;
        TreeNode* root = new TreeNode(preorder[preIndex++]);
        
        int inIndex = inMap[root -> val];
        
        root -> left = cTree(preorder, inorder, is, inIndex-1, inMap);
        root -> right = cTree(preorder, inorder, inIndex+1, ie, inMap);
        
        return root;
    }
};