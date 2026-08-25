class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {

        unordered_set<int> s(nums.begin(), nums.end());

        for (int i = 1; ; i++) {

            int multiple = i * k;

            if (!s.contains(multiple)) {
                return multiple;
            }
        }
    }
};

