class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<long long> sq;

        for (int x : nums) {
            sq.push_back(1LL * x * x);
        }

        sort(sq.begin(), sq.end());

        long long ans = 0;
        int m = nums.size() / 2;

        for (int i = 0; i < sq.size(); i++) {
            if (i < m) ans -= sq[i];
            else ans += sq[i];
        }

        return ans;
    }
};