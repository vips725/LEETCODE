class Solution {
public:
    long long countCommas(long long n) {
        vector<long long> thresholds = {1000LL, 1000000LL, 1000000000LL,
                                        1000000000000LL, 1000000000000000LL,
                                        1000000000000000000LL};
        long long ans = 0;
        for (int i = 0; i < thresholds.size(); i++) {
            long long start = thresholds[i];
            long long end = min(n, (i+1 < thresholds.size() ? thresholds[i+1]-1 : n));
            if (start <= end) {
                ans += (end - start + 1) * (i+1);
            }
        }
        return ans;
    }
};
