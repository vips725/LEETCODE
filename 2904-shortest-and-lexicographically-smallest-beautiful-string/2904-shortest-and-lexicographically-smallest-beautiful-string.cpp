class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        string ans = "";
        for (int i = 0; i < n; ++i) {
            int cnt = 0;
            for (int j = i; j < n; ++j) {
                if (s[j] == '1') cnt++;
                if (cnt == k) {
                    string t = s.substr(i, j - i + 1);
                    if (ans == "" || t.size() < ans.size() || 
                       (t.size() == ans.size() && t < ans)) {
                        ans = t;
                    }
                    break; // shortest for this i found
                }
            }
        }
        return ans;
    }
};
