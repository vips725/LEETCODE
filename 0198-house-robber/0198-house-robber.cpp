class Solution {
public:
    int func(vector<int>& nums,int i , int free,int n ,vector<vector<int>>&dp){
        if(i==n){
            return 0;
        }
        if(dp[i][free]!=-1){
            return dp[i][free];
        }
        if(free == 0){
            return dp[i][free] = func(nums,i+1,1,n,dp);
        }
        int c1 = nums[i]+func(nums,i+1,0,n,dp);
        int c2 = func(nums,i+1,1,n,dp);
        return dp[i][free] = max(c1,c2);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n);
        for(int i =0 ; i < n ; i ++){
            vector<int>t(2,-1);
            dp[i] = t;
        }
        return func(nums,0,1,n,dp);
    }
};