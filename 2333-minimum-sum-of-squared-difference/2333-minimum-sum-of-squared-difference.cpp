class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        vector<int> diff(n);
        int maxDiff = 0;
        
        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            maxDiff = max(maxDiff, diff[i]);
        }
        
        long long k = (long long)k1 + k2;
        vector<long long> freq(maxDiff + 1, 0);
        
        for (int d : diff) freq[d]++;
        
        for (int d = maxDiff; d > 0 && k > 0; d--) {
            if (freq[d] == 0) continue;
            long long take = min((long long)freq[d], k);
            freq[d] -= take;
            freq[d - 1] += take;
            k -= take;
        }
        
        long long ans = 0;
        for (long long d = 0; d <= maxDiff; d++) {
            if (freq[d] > 0) {
                ans += freq[d] * d * d;
            }
        }
        
        return ans;
    }
};
