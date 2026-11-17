class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();

        vector<vector<int>> factors(n + 1);
        for (int len = 2; len <= n; len++) {
            for (int d = 1; d < len; d++) {
                if (len % d == 0)
                    factors[len].push_back(d);
            }
        }

        vector<vector<int>> cost(n, vector<int>(n, 0));

        for (int l = 0; l < n; l++) {
            for (int r = l + 1; r < n; r++) {
                int len = r - l + 1;
                int best = len;

                for (int d : factors[len]) {
                    int cur = 0;

                    for (int offset = 0; offset < d; offset++) {
                        int i = l + offset;
                        int j = r - d + 1 + offset;

                        while (i < j) {
                            if (s[i] != s[j]) cur++;
                            i += d;
                            j -= d;
                        }
                    }

                    best = min(best, cur);
                }

                cost[l][r] = best;
            }
        }

        const int INF = 1e9;

        vector<vector<int>> dp(n + 1, vector<int>(k + 1, INF));
        dp[n][0] = 0;

        for (int i = n - 1; i >= 0; i--) {
            for (int parts = 1; parts <= k; parts++) {

                for (int j = i + 1; j < n; j++) {
                    if (dp[j + 1][parts - 1] == INF) continue;

                    dp[i][parts] = min(
                        dp[i][parts],
                        cost[i][j] + dp[j + 1][parts - 1]
                    );
                }
            }
        }

        return dp[0][k];
    }
};