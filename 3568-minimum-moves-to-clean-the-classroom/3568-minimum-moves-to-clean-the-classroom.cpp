class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {

        int m = classroom.size();
        int n = classroom[0].size();

        // d[i][j] = which litter number is present at (i,j)
        vector<vector<int>> d(m, vector<int>(n, 0));

        int startR = 0;
        int startC = 0;
        int litterCount = 0;

        // Find S and number every L
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (classroom[i][j] == 'S') {
                    startR = i;
                    startC = j;
                }

                else if (classroom[i][j] == 'L') {
                    d[i][j] = litterCount;
                    litterCount++;
                }
            }
        }

        // No litter
        if (litterCount == 0)
            return 0;

        /*
            visited[row][col][energy][mask]

            mask tells us which litter is still NOT collected.

            Example with 3 litter:

            111 = all remaining
            110 = litter 0 collected
            101 = litter 1 collected
            000 = everything collected
        */
        vector<vector<vector<vector<bool>>>> visited(
            m,
            vector<vector<vector<bool>>>(
                n,
                vector<vector<bool>>(
                    energy + 1,
                    vector<bool>(1 << litterCount, false)
                )
            )
        );

        queue<tuple<int, int, int, int>> q;

        // Initially every litter is still present
        int mask = (1 << litterCount) - 1;

        q.push({startR, startC, energy, mask});

        visited[startR][startC][energy][mask] = true;

        int moves = 0;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {

            int size = q.size();

            // Process one BFS level
            while (size--) {

                auto [r, c, currEnergy, mask] = q.front();
                q.pop();

                // All litter collected
                if (mask == 0)
                    return moves;

                // No energy -> cannot move
                if (currEnergy == 0)
                    continue;

                // Try 4 directions
                for (int k = 0; k < 4; k++) {

                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    // Outside grid
                    if (nr < 0 || nr >= m ||
                        nc < 0 || nc >= n)
                        continue;

                    // Wall
                    if (classroom[nr][nc] == 'X')
                        continue;

                    // Moving costs 1 energy
                    int nextEnergy = currEnergy - 1;

                    // Reset area
                    if (classroom[nr][nc] == 'R') {
                        nextEnergy = energy;
                    }

                    int nextMask = mask;

                    // Found litter
                    if (classroom[nr][nc] == 'L') {

                        int litterNumber = d[nr][nc];

                        // Mark this litter as collected
                        nextMask &= ~(1 << litterNumber);
                    }

                    // Have we already visited this exact state?
                    if (visited[nr][nc][nextEnergy][nextMask])
                        continue;

                    visited[nr][nc][nextEnergy][nextMask] = true;

                    q.push({
                        nr,
                        nc,
                        nextEnergy,
                        nextMask
                    });
                }
            }

            moves++;
        }

        return -1;
    }
};