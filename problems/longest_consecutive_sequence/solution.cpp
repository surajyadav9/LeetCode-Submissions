class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> h_set;
        
        int n = nums.size();
        
        // insert into hash O(n)
        for(int i=0; i<n; i++) h_set.insert(nums[i]);
        
        int mx_len=0;
        
        for(int i=0; i<n; i++) {
            if(h_set.find(nums[i]-1) == h_set.end() ) {
                // lower element of current element not found
                // traverse up and count
                int cnt=0, el = nums[i];
                while(h_set.find(el) != h_set.end()) {
                    cnt++;
                    el++;
                }
                
                if(mx_len<cnt) mx_len = cnt;
            }
        }
        
        return mx_len;
    }
};