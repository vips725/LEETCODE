class Solution {
public:
    int findMax(unordered_map<int,int> &f){
        // only care about count of 1s
        return f[1];
    }

    int longestOnes(vector<int>& nums, int k) {
        int low = 0 ; 
        int res = 0; 
        int n = nums.size();
        unordered_map<int , int> f;

        for(int high = 0 ; high < n ; high++){
            f[nums[high]]++;
            int len = high - low + 1;
            int maxcnt = findMax(f);   // count of 1s
            int diff = len - maxcnt;   // number of zeros in window

            while(diff > k){
                f[nums[low]]--;
                low++;
                len = high - low + 1;
                maxcnt = findMax(f);
                diff = len - maxcnt;
            }

            res = max(res , len);
        }
        return res;
    }
};
