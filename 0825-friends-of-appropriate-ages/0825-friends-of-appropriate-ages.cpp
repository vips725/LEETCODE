class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        sort(ages.begin(), ages.end());

        int cnt = 0;
        int n = ages.size();

        for(int age : ages) {

            if(age <= 14) continue;

            int lowAge = age * 0.5 + 7;

            int l = upper_bound(ages.begin(), ages.end(), lowAge) - ages.begin();

            int r = upper_bound(ages.begin(), ages.end(), age) - ages.begin();

            cnt += r - l - 1;
        }

        return cnt;
    }
};