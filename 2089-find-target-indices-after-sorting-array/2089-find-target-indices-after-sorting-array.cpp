class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int n = nums.size();

        // first occurrence
        int low = 0, high = n - 1;
        int first = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] >= target) {
                if (nums[mid] == target) first = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        // target not found
        if (first == -1) return {};

        // last occurrence
        low = 0, high = n - 1;
        int last = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] <= target) {
                if (nums[mid] == target) last = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        vector<int> res;
        for (int i = first; i <= last; i++) {
            res.push_back(i);
        }

        return res;
    }
};