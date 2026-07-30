class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>sub;
        for(int x : nums){
        int low = 0;
        int high = sub.size()-1;
        while(low<=high){
            int mid =(low+high)/2;
            if(sub[mid]<x){
                low = mid+1;
            }else{
                high = mid -1 ;
            }
            }
            if(low < sub.size()){
                sub[low] = x;
            }else{
                sub.push_back(x);
            }
        }
        return sub.size();
    }
};