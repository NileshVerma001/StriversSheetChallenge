class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int c = 0;
        
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                nums[i] = INT_MAX;
            } else {
                c++;
            }
        }
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end(), [](int a, int b){ return a == INT_MAX || b == INT_MAX; }), nums.end());
        
        return c + 1;
    }
};
