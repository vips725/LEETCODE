class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        int nodelete = arr[0];
        int onedelete = INT_MIN;
        int res = arr[0];
        
        for (int i = 1; i < n; i++) {
            int prevnodelete = nodelete;
            int prevonedelete = onedelete;
            
            nodelete = max(arr[i], arr[i] + prevnodelete);
            
            int v2;
            if (prevonedelete == INT_MIN) {
                v2 = arr[i];  // avoid overflow
            } else {
                v2 = arr[i] + prevonedelete;
            }
            onedelete = max(prevnodelete, v2);
            
            res = max({res, nodelete, onedelete});
        }
        return res;
    }
};
