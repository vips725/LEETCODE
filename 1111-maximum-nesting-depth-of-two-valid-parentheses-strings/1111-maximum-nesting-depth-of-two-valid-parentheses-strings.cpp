class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> res;
        int depth = 0;
        for(char c : seq) {
            if(c == '(') {
                depth++;
                res.push_back(depth % 2); // odd → 1 (B), even → 0 (A)
            } else {
                res.push_back(depth % 2);
                depth--;
            }
        }
        return res;
    }
};
