class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<int> dp(n+1, 0);
        
        // Build DP from right to left
        for (int i = n-1; i >= 0; --i) {
            dp[i] = dp[i+1];
            if (dp[i+1] < m && word1[i] == word2[m - dp[i+1] - 1]) {
                dp[i] = dp[i+1] + 1;
            }
        }
        
        vector<int> ans;
        int j = 0, changes = 0;
        for (int i = 0; i < n && j < m; ++i) {
            if (word1[i] == word2[j]) {
                ans.push_back(i);
                j++;
            } else if (changes == 0 && dp[i+1] >= m-j-1) {
                ans.push_back(i);
                j++;
                changes++;
            }
        }
        
        return (j == m ? ans : vector<int>{});
    }
};
