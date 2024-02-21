class Solution {
private:
    void dfs(int node, vector<int>adj[], vector<int>& vis) {
        vis[node] = 1;
        for(auto i:adj[node]) {
            if(!vis[i]) {
                dfs(i,adj,vis);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count=0;
        int n = isConnected.size();
        vector<int>vis(n,0);
        vector<int>adj[n];
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(isConnected[i][j]==1 && i!=j) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        for(int i=0;i<n;i++) {
            if(!vis[i]) {
                count++;
                dfs(i,adj,vis);
            }
        }
        return count;
    }
};