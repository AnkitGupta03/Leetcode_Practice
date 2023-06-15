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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> v;
        if(!root) return v;
        queue<TreeNode *> q;
        stack<int> s;
        bool reverse = false;
        q.push(root);
       
        while(!q.empty()){
            int count = q.size();
            vector<int> temp;
            for(int i=0; i<count; i++){
                TreeNode *curr = q.front();
                q.pop();
                if(reverse)
                    s.push(curr->val);
                else
                    temp.push_back(curr->val);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);       
            }
            if(reverse){
            while(!s.empty()){
                temp.push_back(s.top());
                s.pop();
            }
        }
            reverse = !reverse;
            v.push_back(temp);
        }
        
        return v;
    }
};