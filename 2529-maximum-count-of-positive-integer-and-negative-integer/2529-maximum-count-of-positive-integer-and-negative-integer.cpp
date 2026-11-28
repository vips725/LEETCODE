class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int negcnt = 0;
        int poscnt =0;
        int res=0;
        for(int i = 0; i<n ;i++){
          if(nums[i] > 0){
    poscnt++;
}
else if(nums[i] < 0){
    negcnt++;
}
            res = max(negcnt,poscnt);
        }
        return res;
    }
};