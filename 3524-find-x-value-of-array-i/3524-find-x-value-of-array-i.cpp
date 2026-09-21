class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> res(k, 0);
        
        // dp[r] = number of subarrays ending at current index with product % k = r
        vector<long long> dp(k, 0);
        
        for (int num : nums) {
            vector<long long> newdp(k, 0);
            int modnum = num % k;
            
            // start new subarray with just num
            newdp[modnum]++;
            
            // extend previous subarrays
            for (int r = 0; r < k; r++) {
                if (dp[r] > 0) {
                    int newr = (1LL * r * modnum) % k;
                    newdp[newr] += dp[r];
                }
            }
            
            // add to result
            for (int r = 0; r < k; r++) {
                res[r] += newdp[r];
            }
            
            dp = newdp;
        }
        
        return res;
    }
};
