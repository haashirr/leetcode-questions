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
        if(!root) {
            return result;
        }
        deque<TreeNode*>dq;
        dq.push_back(root);
        bool ltr = true;
        while(!dq.empty()) {
            int n = dq.size();
            vector<int>v;
            while(n--) {
                if(!ltr) {
                    root = dq.back();
                    dq.pop_back();
                    v.push_back(root->val);
                    if(root->right) {
                        dq.push_front(root->right);
                    }
                    if(root->left) {
                        dq.push_front(root->left);
                    }
                }
                else {
                    root = dq.front();
                    dq.pop_front();
                    v.push_back(root->val);
                    if(root->left) {
                        dq.push_back(root->left);
                    }
                    if(root->right) {
                        dq.push_back(root->right);
                    }
                }
            }
            result.push_back(v);
            ltr=!ltr;
        }
        return result;
    }
};