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
private:
    void markParents(TreeNode *root, unordered_map<TreeNode*, TreeNode*> &parent){
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size; i++){
                TreeNode *curr = q.front(); q.pop();
                if(curr -> left){
                    q.push(curr -> left);
                    parent[curr -> left] = curr;
                }
                if(curr -> right){
                    q.push(curr -> right);
                    parent[curr -> right] = curr;
                }
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;     // node -> parent
        markParents(root, parent);
        int distance = 0;
        queue<TreeNode *> q;
        q.push(target);
        unordered_map<TreeNode*, bool> visited;
        visited[target] = true;
        while(!q.empty()){
            int size = q.size();
            if(distance == k) break; // make sure to update the distance before starting next loop;
            for(int i=0; i<size; i++){
                TreeNode *curr = q.front();
                q.pop();
                if(curr -> left && !visited[curr->left]){
                    q.push(curr -> left);
                    visited[curr -> left] = true;
                }
                if(curr -> right && !visited[curr->right]){
                    q.push(curr -> right);
                    visited[curr -> right] = true;
                }
                if(parent[curr] && !visited[parent[curr]]){
                    q.push(parent[curr]);
                    visited[parent[curr]] = true;
                }
            }
            distance++;
        }
        vector<int> res;
        while(!q.empty()){
            TreeNode *curr = q.front(); q.pop();
            res.push_back(curr -> val);
        }
        return res;
    }
};