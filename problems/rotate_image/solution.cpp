class Solution {
public:
    
    void matrix_transpose(vector<vector<int>> &matrix, int n) {
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
    }
    
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        matrix_transpose(matrix, n);
        
        for(int i=0; i<n; i++) {
            // reverse each row
            for(int j=0; j<n/2; j++) {
                int temp = matrix[i][n-j-1];
                matrix[i][n-j-1] = matrix[i][j];
                matrix[i][j] = temp;
            }
        }
    }
};