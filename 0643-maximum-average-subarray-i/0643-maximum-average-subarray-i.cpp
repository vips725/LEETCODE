class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double n = nums.size();
        double sum = 0 ; 
        double res  = INT_MIN;
        double low = 0 ; 
        double high = k-1;
        for(int i = low ; i <=high ; i ++){
            sum = sum + nums[i];
        }
        while(high<n){
            res = max(res,sum);
            low++;
            high++;
            sum = sum - nums[low-1];
            if(high==n){
                break;
            }
            sum = sum + nums[high];
        }
        return res/k;
    }
};