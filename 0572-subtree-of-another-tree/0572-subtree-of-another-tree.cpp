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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) {
            return false; // If the root tree is null, subRoot cannot be a subtree.
        }
        return isSameTree(root, subRoot) || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

private:
    bool isSameTree(TreeNode* a, TreeNode* b) {
        if (!a && !b) {
            return true; // Both trees are null, so they are the same.
        }
        if (!a || !b) {
            return false; // One tree is null, but the other is not, so they are not the same.
        }
        return (a->val == b->val) && isSameTree(a->left, b->left) && isSameTree(a->right, b->right);
    }
};
