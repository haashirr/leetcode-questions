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
    bool isBalanced(TreeNode* root) {
        if(!root) {
            //empty binary tree is considered as balanced
            return true;
        }
        int leftTree = getHeight(root->left);
        int rightTree = getHeight(root->right);
        if(abs(leftTree-rightTree)<=1 && isBalanced(root->left) && isBalanced(root->right)) {
            return true;
        }
        return false;
    }
    int getHeight(TreeNode* root) {
        if(root==NULL) {
            return 0;
        }
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);

        return max(leftHeight,rightHeight)+1;
    }
};