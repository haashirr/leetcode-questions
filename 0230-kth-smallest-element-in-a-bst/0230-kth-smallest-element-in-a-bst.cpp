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
    void dfs(TreeNode* root,queue<TreeNode*>&q) {
        if(!root) {
            return;
        }
        if(!root->left && !root->right) {
            q.push(root);
            return;
        }
        if(!root->left) {
            q.push(root);
            dfs(root->right,q);
        }
        else if(!root->right) {
            dfs(root->left,q);
            q.push(root);
        }
        else {
            dfs(root->left,q);
            q.push(root);
            dfs(root->right,q);
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        queue<TreeNode*>q;
        dfs(root,q);
        while(--k) {
            q.pop();
        }
        return q.front()->val;
    }
};