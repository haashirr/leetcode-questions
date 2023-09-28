class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        //reverse
     
            reverse(matrix.begin(),matrix.end());
        
        //transpose
        for(int i=0;i<matrix.size();i++) {
            for(int j=i;j<matrix[i].size();j++) {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        
    }
};