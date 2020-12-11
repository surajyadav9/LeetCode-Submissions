class Solution {
public:
    int uniquePaths(int m, int n) {
        int N = m + n -2;
        int r = min(m-1, n-1);
        
        long long int res = 1LL;
        for(int i=1; i<=r; i++) {
            res *= (N-r+i);
            res /= i;
        }
        
        return res;
        
        
    }
};