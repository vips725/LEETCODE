class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        const int MOD = 1e9 + 7;
        using T = tuple<int,int,int>; // (sum, start, end)
        priority_queue<T, vector<T>, greater<T>> pq;
        
        // initialize heap with subarrays starting at each index
        for (int i = 0; i < n; i++) {
            pq.emplace(nums[i], i, i);
        }
        
        long long ans = 0;
        for (int k = 1; k <= right; k++) {
            auto [sum, i, j] = pq.top(); pq.pop();
            if (k >= left) ans = (ans + sum) % MOD;
            if (j + 1 < n) {
                pq.emplace(sum + nums[j+1], i, j+1);
            }
        }
        return ans;
    }
};
