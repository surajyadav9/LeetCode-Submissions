class Solution {
public:
    bool checkOnesSegment(string s) {
        int cnt=0;
        for(int i=0; i<(int)s.size(); i++) {
            if(s[i]=='1') {
                cnt++;
                while(i<(int)s.size() && s[i]=='1') i++;
            }
        }
        
        if(cnt==1) return true;
        else return false;
    }
};