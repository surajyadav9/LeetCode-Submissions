class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> merged;
        int n = intervals.size();
        
        if(n==0) {
            return merged;
        }
        
        sort(intervals.begin(), intervals.end());
        int st = intervals[0][0], en = intervals[0][1];
        
        for(int i=1; i<n; i++) {
            if(intervals[i][0] <= en) {
                en = max(en, intervals[i][1]);
            }
            else {
                vector<int> v(2);
                v[0] = st, v[1] = en;
                merged.push_back(v);
                
                // set 'st' and 'en' to new values
                st = intervals[i][0], en = intervals[i][1];
            }
        }
        
        vector<int> v(2);
        v[0] = st, v[1] = en;
        merged.push_back(v);
        
        return merged;
    }
};