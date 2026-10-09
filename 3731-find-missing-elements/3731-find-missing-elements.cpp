class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int low = *min_element(nums.begin(), nums.end());
        int high = *max_element(nums.begin(), nums.end());
        
        unordered_set<int> st(nums.begin(), nums.end());
        vector<int> res;
        
        for (int x = low; x <= high; x++) {
            if (st.find(x) == st.end()) {
                res.push_back(x);
            }
        }
        return res;
    }
};
