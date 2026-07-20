class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        bool inserted = false;

        // First loop: insert newInterval at the right place
        for (int i = 0; i < intervals.size(); i++) {
            if (!inserted && intervals[i][0] >= newInterval[0]) {
                res.push_back(newInterval);
                inserted = true;
            }
            res.push_back(intervals[i]);
        }
        if (!inserted) res.push_back(newInterval);

        // Second loop: merge intervals
        vector<vector<int>> ans;
        int s1 = res[0][0];
        int e1 = res[0][1];

        for (int i = 1; i < res.size(); i++) {
            int s2 = res[i][0];
            int e2 = res[i][1];   // ✅ fixed indexing

            if (e1 >= s2) {
                e1 = max(e1, e2);
            } else {
                ans.push_back({s1, e1});
                s1 = s2;
                e1 = e2;
            }
        }
        ans.push_back({s1, e1});
        return ans;
    }
};
