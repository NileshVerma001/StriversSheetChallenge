class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (int i = 0; i < matrix.size(); i++) {
            int l = 0, r = matrix[i].size() - 1;
            
            while (l <= r) {  // Changed the condition from l < r to l <= r
                int mid = l + (r - l) / 2;  // Fixed the calculation of mid
                
                if (matrix[i][mid] == target)
                    return true;

                if (matrix[i][mid] > target)
                    r = mid - 1;
                else
                    l = mid + 1;
            }
        }
        return false;
    }
};
