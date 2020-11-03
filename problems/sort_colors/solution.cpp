class Solution {
public:
    
    void swap(int &a, int &b) {
        int t = a;
        a = b;
        b = t;
    }
    
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        
        int low, mid , high;
        low = mid =  0;
        high = n-1;
        
        while(mid<=high) {
            if(nums[mid]==0) {
                swap(nums[low], nums[mid]);
                mid++;
                low++;
            }
            else if(nums[mid]==2) {
                swap(nums[mid], nums[high]);
                high--;
            }
            else {
                mid++;
            }
        }
    }
};