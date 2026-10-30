class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<int>& colors, int node) {

        colors[node] = 1; // Currently visiting

        for (int neigh : graph[node]) {

            // Found a cycle
            if (colors[neigh] == 1) {
                return false;
            }

            // Not visited
            if (colors[neigh] == 0) {
                if (!dfs(graph, colors, neigh)) {
                    return false;
                }
            }
        }

        colors[node] = 2; // Completely processed
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> graph(numCourses);

        // Build directed graph
        for (auto p : prerequisites) {
            graph[p[1]].push_back(p[0]);
        }

        vector<int> colors(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {

            if (colors[i] == 0) {
                if (!dfs(graph, colors, i)) {
                    return false;
                }
            }
        }

        return true;
    }
};