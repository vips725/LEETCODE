class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> prefix(n+1, 0);
        for (int i = 0; i < n; i++) prefix[i+1] = prefix[i] + stoneValue[i];
        
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        function<int(int,int)> solve = [&](int l, int r) {
            if (l == r) return 0;
            if (dp[l][r] != 0) return dp[l][r];
            
            int best = 0;
            for (int k = l; k < r; k++) {
                int left = prefix[k+1] - prefix[l];
                int right = prefix[r+1] - prefix[k+1];
                if (left < right) best = max(best, left + solve(l, k));
                else if (left > right) best = max(best, right + solve(k+1, r));
                else best = max(best, max(left + solve(l, k), right + solve(k+1, r)));
            }
            return dp[l][r] = best;
        };
        
        return solve(0, n-1);
    }
};
