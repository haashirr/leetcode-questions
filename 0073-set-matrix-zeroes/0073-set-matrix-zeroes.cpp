class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        unordered_set<int>s1;
        unordered_set<int>s2;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(matrix[i][j]==0) {
                    s1.insert(i);
                    s2.insert(j);
                }
            }
        }
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(s1.count(i)>0 || s2.count(j)>0) {
                    matrix[i][j]=0;
                }
            }
        }
    }
};