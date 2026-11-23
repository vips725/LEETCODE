
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty,
                            vector<int>& profit,
                            vector<int>& worker) {

        int n = difficulty.size();

        vector<pair<int,int>> jobs;

        for(int i = 0; i < n; i++) {
            jobs.push_back({difficulty[i], profit[i]});
        }

        sort(jobs.begin(), jobs.end());

        // Build prefix maximum profit
        vector<int> prefix(n);

        prefix[0] = jobs[0].second;

        for(int i = 1; i < n; i++) {
            prefix[i] = max(prefix[i-1], jobs[i].second);
        }

        int ans = 0;

        for(int w : worker) {

            int low = 0;
            int high = n - 1;
            int idx = -1;

            while(low <= high) {

                int mid = low + (high - low) / 2;

                if(jobs[mid].first <= w) {
                    idx = mid;
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }

            if(idx != -1) {
                ans += prefix[idx];
            }
        }

        return ans;
    }
};
