class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int>res(n,INT_MAX);
        res[src] = 0 ;
        int i;
        for( i = 0 ; i <=k ; i++){
            vector<int>tmp = res;
            for(int j = 0; j<flights.size();j++){
                int s = flights[j][0];
                int d = flights[j][1];
                int wt = flights[j][2];
                if(res[s]!=INT_MAX && tmp[d] > res[s]+wt){
                    tmp[d] = res[s] + wt;
                }
            }
            res = tmp;
        }
         if(res[dst]==INT_MAX){
                return -1;
            }
        return res[dst];
    }
};