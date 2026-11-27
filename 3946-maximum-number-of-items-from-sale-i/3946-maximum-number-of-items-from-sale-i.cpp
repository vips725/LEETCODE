class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        vector<int> freeCnt(n, 1);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && items[j][0] % items[i][0] == 0) {
                    freeCnt[i]++;
                }
            }
        }

        vector<vector<int>> dp(n + 1, vector<int>(budget + 1, 0));
        for (int i = n - 1; i >= 0; i--) {
            int cost = items[i][1];
            for (int j = 0; j <= budget; j++) {
                dp[i][j] = dp[i + 1][j];
                if (j >= cost) {
                    // first copy of item i
                    dp[i][j] = max(
                        dp[i][j],
                        dp[i + 1][j - cost] + freeCnt[i]
                    );
                    // additional copies of same item
                    dp[i][j] = max(
                        dp[i][j],
                        dp[i][j - cost] + 1
                    );
                }
            }
        }
        return dp[0][budget];
    }
};