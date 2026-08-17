class Solution {
public:
    int help(vector<int>& candies, long long k , long long candy){
        long long h = 0 ;
        for(int i = 0 ; i < candies.size() ;i++){
            h = h + candies[i]/candy;
        }
        return h>=k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();
        long  low = 1 ;
        long ans = 0;
        int high = *max_element(candies.begin(), candies.end());
        while(low<=high){
            long long guess = (low+high)/2;
            if(help(candies, k, guess)){
                ans = guess;
                low = guess +1;
            }else{  
                high = guess - 1;
            }
        }
        return ans;
    }
};