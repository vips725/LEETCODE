class Solution {
public:
    long long help(vector<int>& piles, int speed) {
        long long hours = 0;

        for (int bananas : piles) {
            // Ceiling division
            hours += (bananas + speed - 1) / speed;
        }

        return hours;
    }

    int maxofarray(vector<int>& piles) {
        int res = INT_MIN;

        for (int bananas : piles) {
            res = max(res, bananas);
        }

        return res;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = maxofarray(piles);
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            long long hours = help(piles, mid);

            if (hours <= h) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};