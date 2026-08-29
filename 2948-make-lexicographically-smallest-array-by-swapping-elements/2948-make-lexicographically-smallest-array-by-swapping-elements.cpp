class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        // DSU parent mapping
        unordered_map<int,int> parent;
        auto find = [&](auto&& self, int x) -> int {
            if (parent[x] != x) parent[x] = self(self, parent[x]);
            return parent[x];
        };
        auto unite = [&](int a, int b) {
            int pa = find(find, a), pb = find(find, b);
            if (pa != pb) parent[pb] = pa;
        };

        // Initialize DSU
        for (int x : sorted) parent[x] = x;

        // Union consecutive values if difference <= limit
        for (int i = 1; i < n; i++) {
            if (sorted[i] - sorted[i-1] <= limit) {
                unite(sorted[i], sorted[i-1]);
            }
        }

        // Group values by DSU root
        unordered_map<int, vector<int>> groups;
        for (int x : sorted) {
            groups[find(find, x)].push_back(x);
        }
        // Sort each group descending for efficient pop_back
        for (auto& [root, vec] : groups) {
            sort(vec.rbegin(), vec.rend());
        }

        // Build result
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            int root = find(find, nums[i]);
            res[i] = groups[root].back();
            groups[root].pop_back();
        }
        return res;
    }
};
