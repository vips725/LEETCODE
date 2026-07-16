class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int , int> f;
        int zero = 0 ; 
        int one = 0 ; 
        int n = nums.size();
        int res = 0;
        for(int i = 0 ; i <n ; i++){
            if(nums[i] == 0){
                zero++;
            }
            else{
                one++;
            }
            int diff = zero - one;
            if(diff==0){
                res = max(res,i+1);
                continue;
            }
            if(f.find(diff)==f.end()){
                f[diff] = i;
            }
            else{
                int idx = f[diff];
                int len = i - f[diff];
                res = max(len,res);
            }
        }
        return res;
    }
};