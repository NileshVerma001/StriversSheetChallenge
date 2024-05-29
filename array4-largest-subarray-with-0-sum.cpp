class Solution {
public:
    int maxLen(vector<int>& A, int n) {
        int ans = 0;
        unordered_map<int, int> prefixSumIndex;
        int sum = 0;
        
        for (int i = 0; i < n; i++) {
            sum += A[i];
            
            if (sum == 0) {
                ans = i + 1; 
            } else {
                if (prefixSumIndex.find(sum) != prefixSumIndex.end()) {
                    ans = max(ans, i - prefixSumIndex[sum]);
                } else {
                    prefixSumIndex[sum] = i;
                }
            }
        }
        
        return ans;
    }
};
