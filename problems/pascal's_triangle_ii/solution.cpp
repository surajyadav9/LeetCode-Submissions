class Solution {
public:
    vector<int> getRow(int n) {
        vector<int> upper(n+1, 0), lower(n+1, 0);
        
        upper[0] = 1;
        
        for(int i=1; i<=n; i++) {
            lower[0] = 1;
            for(int j=1; j<=i; j++)     {
                lower[j] = upper[j-1] + upper[j];
            }
            upper = lower;
        }
        
        return upper;
    }
};