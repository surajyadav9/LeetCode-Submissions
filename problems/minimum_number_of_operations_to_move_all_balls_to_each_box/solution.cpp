class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.length();
        vector<int> res(n, 0);
        
        for(int i=0, cnt=0, ops=0; i<n; i++) {
            res[i]  += ops;
            cnt += boxes[i] == '1'? 1 : 0;
            ops += cnt;
        }
        
        for(int i=n-1, cnt=0, ops=0; i>=0; i--) {
            res[i]  += ops;
            cnt += boxes[i] == '1'? 1 : 0;
            ops += cnt;
        }
        
        return res;
    }
};