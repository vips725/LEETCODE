class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int i , j ;
        int sum = 0;
        int n = nums.size();
        for(i = 0 ; i<n;i++){
            sum+=nums[i];
        }
        if((sum + target) % 2!=0)return 0;
        if(abs(target)>sum)return 0;
        vector<vector<int>> dp(n+1);
        int s = (sum+target)/2;

        for(i = 0; i <= n ; i++){
            vector<int>t(s+1,-1);
            dp[i] = t;
        }

        for(int j = 0 ; j <=s ; j++){
            dp[n][j] = 0;
        }

        dp[n][0] = 1;

        for(i=n-1;i>=0;i--){
            for(j=0 ;j<=s;j++){
                if(nums[i]>j){
                    dp[i][j] = dp[i+1][j];
                }
                else{
                    dp[i][j] = dp[i+1][j-nums[i]] + dp[i+1][j];
                }
            }
        }
        return dp[0][s];
    }
};