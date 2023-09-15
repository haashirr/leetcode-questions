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
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long,int>mp;
        mp[0]=1;
        int count = 0;
        dfs(root,targetSum,0,mp,count);
        return count;
    }
    void dfs(TreeNode* root, int targetSum, long long currentSum, unordered_map<long long, int>&mp, int &count) {
        if(!root) {
            return;
        }
        currentSum += root->val;
        if(mp.find(currentSum-targetSum)!=mp.end()) {
            count+=mp[currentSum-targetSum];
        }
        mp[currentSum]++;
        dfs(root->left,targetSum,currentSum,mp,count);
        dfs(root->right,targetSum,currentSum,mp,count);
        mp[currentSum]--;
    }
};