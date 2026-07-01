class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, -1));
        queue<pair<int,int>> q;

        // Step 1: Multi-source BFS from all thieves
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1) {
                    dist[i][j] = 0;
                    q.push({i,j});
                }
            }
        }

        int dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        while(!q.empty()) {
            auto [r,c] = q.front(); q.pop();
            for(auto& d : dirs) {
                int nr = r + d[0], nc = c + d[1];
                if(nr>=0 && nr<n && nc>=0 && nc<n && dist[nr][nc] == -1) {
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr,nc});
                }
            }
        }

        // Step 2: Dijkstra-like search with max-heap
        priority_queue<array<int,3>> pq; // {safeness, row, col}
        pq.push({dist[0][0], 0, 0});
        vector<vector<int>> best(n, vector<int>(n, -1));
        best[0][0] = dist[0][0];

        while(!pq.empty()) {
            auto [safe, r, c] = pq.top(); pq.pop();
            if(r == n-1 && c == n-1) return safe;

            for(auto& d : dirs) {
                int nr = r + d[0], nc = c + d[1];
                if(nr>=0 && nr<n && nc>=0 && nc<n) {
                    int newSafe = min(safe, dist[nr][nc]);
                    if(newSafe > best[nr][nc]) {
                        best[nr][nc] = newSafe;
                        pq.push({newSafe, nr, nc});
                    }
                }
            }
        }
        return 0;
    }
};
