class Solution {
public:
    bool isAnagram(string s, string t) {
      if (s.length() != t.length()) {
            return false;
        }

    unordered_map<char ,int>j;
    unordered_map<char ,int>k;
    for(int i =0  ;i < s.length() ; i ++){
        j[s[i]]++;
        k[t[i]]++;
    }
    return j == k;
    }
};