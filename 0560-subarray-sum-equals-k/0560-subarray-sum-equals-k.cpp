class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int > f;
        int sum =0 ;
        int res =0 ; 
        f[0] = 1;
        for(int i =0 ; i < n ; i ++){
            sum = sum + nums[i];
            int ques = sum-k;
            int freq = f[ques];
            res+=freq;
            f[sum]++;
        }
        return res;
    }
};