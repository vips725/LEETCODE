class Solution {
public:
    int func(int i, int n, unordered_map<int,int>& dp) {
        if (i == n) return 1;
        if (i > n) return 0;
        
        if (dp.find(i) != dp.end()) return dp[i];
        
        int a1 = func(i+1, n, dp);
        int a2 = func(i+2, n, dp);
        
        dp[i] = a1 + a2;
        return dp[i];
    }
    
    int climbStairs(int n) {
        unordered_map<int,int> dp;
        return func(0, n, dp);
    }
};
