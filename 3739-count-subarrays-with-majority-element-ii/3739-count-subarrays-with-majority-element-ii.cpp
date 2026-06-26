class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> score(n);
        for (int i = 0; i < n; i++) {
            score[i] = (nums[i] == target ? 1 : -1);
        }

        // prefix sums
        vector<long long> prefix(n+1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i+1] = prefix[i] + score[i];
        }

        // coordinate compression
        vector<long long> all = prefix;
        sort(all.begin(), all.end());
        all.erase(unique(all.begin(), all.end()), all.end());

        auto getIndex = [&](long long x) {
            return (int)(lower_bound(all.begin(), all.end(), x) - all.begin()) + 1;
        };

        // Fenwick Tree
        vector<int> BIT(all.size()+2, 0);
        auto update = [&](int idx) {
            for (; idx < (int)BIT.size(); idx += idx & -idx) BIT[idx]++;
        };
        auto query = [&](int idx) {
            int sum = 0;
            for (; idx > 0; idx -= idx & -idx) sum += BIT[idx];
            return sum;
        };

        long long ans = 0;
        for (int i = 0; i <= n; i++) {
            int idx = getIndex(prefix[i]);
            // count how many previous prefix < current prefix
            ans += query(idx-1);
            update(idx);
        }

        return ans;
    }
};
