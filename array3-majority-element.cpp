class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int count = 1;
        int majority = nums[0];
        int maxCount = 1;
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                count++;
            } else {
                if (count > maxCount) {
                    majority = nums[i - 1];
                    maxCount = count;
                }
                count = 1;
            }
        }

        if (count > maxCount) {
            majority = nums[nums.size() - 1];
        }
        
        return majority;
    }
};
