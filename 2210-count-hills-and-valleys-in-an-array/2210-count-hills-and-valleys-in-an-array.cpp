class Solution {
public:
    int countHillValley(vector<int>& nums) {

        vector<int> arr;

        for(int i = 0; i < nums.size(); i++) {

            if(arr.empty() || arr.back() != nums[i]) {
                arr.push_back(nums[i]);
            }
        }

        int count = 0;

        for(int i = 1; i < arr.size()-1; i++) {

            if(arr[i] > arr[i-1] && arr[i] > arr[i+1]) {
                count++;
            }

            else if(arr[i] < arr[i-1] && arr[i] < arr[i+1]) {
                count++;
            }
        }

        return count;
    }
};