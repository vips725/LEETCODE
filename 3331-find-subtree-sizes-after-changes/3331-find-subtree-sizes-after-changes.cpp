
class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        vector<vector<int>> adj(n);

        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        vector<int> newParent(n);
        vector<int> ans(n, 1);
        vector<int> st[26];

        function<void(int)> dfs = [&](int node) {
            int c = s[node] - 'a';

            // Find nearest ancestor with the same character
            if (!st[c].empty()) {
                newParent[node] = st[c].back();
            } else {
                newParent[node] = parent[node];
            }

            st[c].push_back(node);

            for (int child : adj[node]) {
                dfs(child);
            }

            st[c].pop_back();
        };

        dfs(0);

        // Build the modified tree
        vector<vector<int>> newAdj(n);

        for (int i = 1; i < n; i++) {
            newAdj[newParent[i]].push_back(i);
        }

        // Calculate subtree sizes
        function<int(int)> calculate = [&](int node) {
            int size = 1;

            for (int child : newAdj[node]) {
                size += calculate(child);
            }

            ans[node] = size;
            return size;
        };

        calculate(0);

        return ans;
    }
};

