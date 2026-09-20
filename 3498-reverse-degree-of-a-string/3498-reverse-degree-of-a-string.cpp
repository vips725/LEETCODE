class Solution {
public:
    int reverseDegree(string s) {
        int n = s.size();
        int result = 0;
        for (int i = 0; i < n; i++) {
            int revIndex = 26 - (s[i] - 'a'); // 'a' = 26, 'z' = 1
            result += revIndex * (i + 1);     // position is 1-indexed
        }
        return result;
    }
};
