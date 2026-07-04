class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
    vector<vector<pair<int,int>>> graph(n+1);
    for (auto &r : roads) {
        graph[r[0]].push_back({r[1], r[2]});
        graph[r[1]].push_back({r[0], r[2]});
    }
    
    vector<int> visited(n+1, 0);
    int ans = INT_MAX;
    
    queue<int> q;
    q.push(1);
    visited[1] = 1;
    
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto &edge : graph[u]) {
            int v = edge.first, w = edge.second;
            ans = min(ans, w);
            if (!visited[v]) {
                visited[v] = 1;
                q.push(v);
            }
        }
    }
    
    return ans;
}

};