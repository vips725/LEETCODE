class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<pair<int,int>> aOnes, bOnes;
        int n = A.size();
        
        // Collect coordinates of 1s in both matrices
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(A[i][j] == 1) aOnes.push_back({i,j});
                if(B[i][j] == 1) bOnes.push_back({i,j});
            }
        }
        
        unordered_map<long long,int> shiftCount;
        int maxOverlap = 0;
        
        // Compare all 1s in A with all 1s in B
        for(auto &a : aOnes){
            for(auto &b : bOnes){
                int dx = a.first - b.first;
                int dy = a.second - b.second;
                long long key = ((long long)dx << 32) | (dy & 0xffffffff);
                maxOverlap = max(maxOverlap, ++shiftCount[key]);
            }
        }
        
        return maxOverlap;
    }
};
