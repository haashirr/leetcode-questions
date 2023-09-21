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
    bool isValidBST(TreeNode* root) {
        //function overloading
        return isValidBST(root,LONG_MIN,LONG_MAX);
    }
    bool isValidBST(TreeNode* root, long minVal, long maxVal) {
        if(!root) {
            return true;
        }
        if(root->val<=minVal || root->val>=maxVal) {
            return false;
        }
        bool isLeftBST = isValidBST(root->left,minVal,root->val);
        bool isRightBST = isValidBST(root->right,root->val,maxVal);
        bool isDuplicate = (root->left && root->left->val==root->val) || (root->right && root->right->val==root->val);

        return isLeftBST && isRightBST && !isDuplicate;
    }
};