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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) {
            return 0;
        }
        int ans=1;
        queue<pair<TreeNode*,long long int>>q;
        q.push({root,0});
        while(!q.empty()) {
            int n = q.size();
            int left=0;
            int right=0;
            int temp = q.front().second;
            for(int i=0;i<n;i++) {
                auto p = q.front();
                TreeNode* b = p.first;
                long long int k = p.second-temp;
                q.pop();
                if(i==0) {
                    left = k;
                }
                if(i==n-1) {
                    right = k;
                }
                if(b->left) {
                    q.push({b->left,2*k+1});
                }
                if(b->right) {
                    q.push({b->right,2*k+2});
                }
            }
            ans = max(ans,right-left+1);
        }
        return ans;
    }
};