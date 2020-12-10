class Solution {
public:
    int uniquePaths(int m, int n) {
        int grid[m][n];
        
        // There is only 1 path from Right-most and Bottom-most column
        
        // Assigning 1 to the Right-most column
        for(int r=0; r<m; r++) grid[r][n-1]=1;
        
        // Assigning 1 to the Bottom-most column
        for(int c=0; c<n; c++) grid[m-1][c]=1;
        
        grid[m-1][n-1] = 1;
        
        for(int c=n-2; c>=0; c--) {
            for(int r=m-2; r>=0; r--) {
                grid[r][c] = grid[r+1][c] + grid[r][c+1];
            }
        }
        
        return grid[0][0];
    }
};