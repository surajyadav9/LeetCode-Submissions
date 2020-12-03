class Solution {
public:
    int titleToNumber(string s) {
        int n = s.size();
        int num = 0;
        
        for(int i=0; i<n; i++) {
            num += (s[n-i-1]-'A'+1) * pow(26, i);
        }
        
        return num;
    }
};