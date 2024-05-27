class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });

        for (int i = 0; i < intervals.size(); i++) {
            int s = intervals[i][0], e = intervals[i][1];

            while (i + 1 < intervals.size() && e >= intervals[i + 1][0]) {
                e = max(e, intervals[i + 1][1]);
                i++;
            }
            result.push_back({s, xe});
        }
        return result;
    }
};
