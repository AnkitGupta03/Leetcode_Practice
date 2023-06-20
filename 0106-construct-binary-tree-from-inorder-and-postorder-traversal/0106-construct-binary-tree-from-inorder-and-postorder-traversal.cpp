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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int> inMap;
        for(int i=0; i<inorder.size(); i++){
            inMap[inorder[i]] = i;
        }
        
        TreeNode *root = cTree(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1, inMap);
        return root;
    }
    
    TreeNode* cTree(vector<int>& inorder, int is, int ie, vector<int>& postorder, int ps, int pe, map<int, int>& inMap){
        if(is > ie) return NULL;
        
        TreeNode* root = new TreeNode(postorder[pe]);
        int inRoot = inMap[root -> val];
        int numsleft = inRoot - is;
        
        root -> left = cTree(inorder, is, inRoot -1, postorder, ps, ps+numsleft-1, inMap);
        root -> right = cTree(inorder, inRoot+1, ie, postorder, ps+numsleft, pe-1, inMap);
        
        return root;
    }
};