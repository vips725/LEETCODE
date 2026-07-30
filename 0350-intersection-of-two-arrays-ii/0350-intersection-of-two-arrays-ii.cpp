class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        int low1 = 0, high1 = nums1.size() - 1;
        int low2 = 0, high2 = nums2.size() - 1;
        vector<int> ans;
        
        while(low1 <= high1 && low2 <= high2) {
            if(nums1[low1] == nums2[low2]) {
                ans.push_back(nums1[low1]);
                low1++;
                low2++;
            } else if(nums1[low1] < nums2[low2]) {
                low1++;
            } else {
                low2++;
            }
        }
        return ans;
    }
};
