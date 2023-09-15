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
public:
    unordered_map<TreeNode*,TreeNode*>parent;
    void dfs(TreeNode* vertex, TreeNode* par) {
        if(!vertex) {
            return;
        }
        parent[vertex] = par;
        dfs(vertex->left,vertex);
        dfs(vertex->right,vertex);
    }
    vector<TreeNode*>path(TreeNode* vertex) {
        vector<TreeNode*>ans;
        while(vertex!=NULL) {
            ans.push_back(vertex);
            vertex = parent[vertex];
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root,NULL);
        vector<TreeNode*>path_x = path(p);
        vector<TreeNode*>path_y = path(q);
        int min_len = min(path_x.size(),path_y.size());
        TreeNode* lca=NULL;
        for(int i=0;i<min_len;i++) {
            if(path_x[i]==path_y[i]) {
                lca = path_x[i];
            }
            else {
                break;
            }
        }
        return lca;
    }
};