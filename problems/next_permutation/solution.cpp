class Solution {
public:
    void swap(int &a, int &b) {
        int t = a;
        a = b;
        b = t;
    }
    
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int pivot;
        
        for(int i=n-2; i>=0; i--) {
            if(nums[i]<nums[i+1]) {
                pivot = i; // i be the pivot index
                for(int j=n-1; j>i; j--) {
                    if(nums[pivot]<nums[j]) {
                        swap(nums[pivot], nums[j]);
                        // reverse
                        int size = n - pivot - 1;
                        for(int k=0; k<size/2; k++) {
                            swap(nums[pivot+k+1], nums[n-1-k]);
                        }
                        return;
                    }
                }
            }
        }
        
        // reverse array
        for(int i=0; i<n/2; i++) {
            swap(nums[i], nums[n-i-1]);
        }
        
    }
};