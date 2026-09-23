class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        int target = total - x;
        if (target < 0) return -1;

        int n = nums.size();
        int left = 0, curr = 0, maxLen = -1;

        for (int right = 0; right < n; right++) {
            curr += nums[right];
            while (curr > target && left <= right) {
                curr -= nums[left++];
            }
            if (curr == target) {
                maxLen = max(maxLen, right - left + 1);
            }
        }
        return (maxLen == -1) ? -1 : n - maxLen;
    }
};
