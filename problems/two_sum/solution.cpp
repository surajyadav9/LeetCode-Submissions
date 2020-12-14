class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int, int> mp; // <value, idx>
        
        for(int i=0; i<(int)nums.size(); i++) {
            int req = target - nums[i];
            if(mp.find(req) != mp.end()) {
                ans.push_back(mp[req]);
                ans.push_back(i);
                break;
            }
            else {
                mp[nums[i]] = i;
            }
        }
        
        return ans;
        
    }
};