class Solution {
public:
    vector<int> res;

    bool dfs(vector<vector<int>>& a, vector<int>& colors, int node) {

        colors[node] = 1; // Currently visiting

        for (int j = 0; j < a[node].size(); j++) {

            int neigh = a[node][j];

            if (colors[neigh] == 1) {
                return false;
            }

            if (colors[neigh] == 0) {
                if (!dfs(a, colors, neigh)) {
                    return false;
                }
            }
        }

        colors[node] = 2; // Completely processed
        res.push_back(node);

        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> a(numCourses);

        for (auto p : prerequisites) {
            a[p[1]].push_back(p[0]);
        }

        vector<int> colors(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {

            if (colors[i] == 0) {
                if (!dfs(a, colors, i)) {
                    return {};
                }
            }
        }

        reverse(res.begin(), res.end());

        return res;
    }
};