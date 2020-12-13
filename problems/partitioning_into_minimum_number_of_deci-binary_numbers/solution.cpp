class Solution {
public:
    int minPartitions(string s) {
        int mx = 0;
        for(int i=0; i<s.length() ; i++) {
            mx = max(mx, s[i]-48);
        }
        
        return mx;
    }
};