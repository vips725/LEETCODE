class Solution {
public:
    bool backspaceCompare(string s, string t) {
        vector<char> ans;
        vector<char> anss;

        // process s
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '#') {
                if (!ans.empty()) ans.pop_back();
            } else {
                ans.push_back(s[i]);
            }
        }

        // process t
        for (int j = 0; j < t.size(); j++) {
            if (t[j] == '#') {
                if (!anss.empty()) anss.pop_back();
            } else {
                anss.push_back(t[j]);
            }
        }

        return ans == anss;
    }
};
