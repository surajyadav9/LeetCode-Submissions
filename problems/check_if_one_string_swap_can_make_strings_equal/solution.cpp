class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1 == s2)
            return true;
        
        int n = s1.size();
        
        int f1[26], f2[26];
        for(int i=0; i<26; i++) f1[i] = f2[i] = 0;
        
        for(int i=0; i<n; i++) f1[s1[i]-97]++, f2[s2[i]-97]++;
        
        int cnt=0;
        for(int i=0; i<n; i++) {
            if(s1[i] != s2[i]) {
                if((f1[s1[i]-97] == f2[s1[i]-97]) && (f1[s2[i]-97] == f2[s2[i]-97])) 
                    cnt++;
                else
                    return false;
            }
        }
        
        if(cnt/2 + cnt%2 > 1)
            return false;
        else
            return true;
    }
};