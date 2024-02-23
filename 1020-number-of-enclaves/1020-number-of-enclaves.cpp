class Solution {
private:
    void dfs(vector<vector<int>>& grid, int i, int j, int m, int n) {
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j]!=1) {
            return;
        } 
        grid[i][j] = 2;
        int ai[] = {0,1,0,-1};
        int aj[] = {1,0,-1,0};
        for(int k=0;k<4;k++) {
            dfs(grid,i+ai[k],j+aj[k],m,n);
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0;i<m;i++) {
            dfs(grid, i, 0, m, n);
            dfs(grid, i, n-1, m, n);
        }
        for(int j=0;j<n;j++) {
            dfs(grid,0,j,m,n);
            dfs(grid,m-1,j,m,n);
        }
        int count = 0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]==1) {
                    count++;
                }
            }
        }
        return count;
    }
};