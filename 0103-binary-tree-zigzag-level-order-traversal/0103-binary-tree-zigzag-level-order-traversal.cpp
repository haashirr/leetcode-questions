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
        vector<vector<int>>result;
        if(root==NULL) {
            return result;
        }
        queue<TreeNode*>q;
        q.push(root);
        int flag=0;
        while(!q.empty()) {
            int size = q.size();
            vector<int>v(size);
            for(int i=0;i<size;i++) {
                TreeNode* temp = q.front();
                q.pop();
                if(flag) {
                    v[size-i-1] = temp->val;
                }
                else {
                    v[i] = temp->val;
                }
                if(temp->left) {
                    q.push(temp->left);
                }
                if(temp->right) {
                    q.push(temp->right);
                }
            }
            result.push_back(v);
            flag = !flag;
        }
        return result;
    }
};