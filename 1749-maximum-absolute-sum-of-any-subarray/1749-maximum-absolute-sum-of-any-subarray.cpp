class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int bestending=nums[0];
        int ans = nums[0];
        int worstending = nums[0];
        int res = max(abs(nums[0]), 0);
        for(int i = 1 ; i < n ; i++){
            int v1 = bestending + nums[i];
            int v2 = nums[i];
            int v3 = worstending + nums[i];
            bestending = max(v1,v2);
            worstending = min(v2,v3);
            int v4 = abs(worstending);
            res = max({res,abs(bestending),v4});
        }
        return res;
    }
};