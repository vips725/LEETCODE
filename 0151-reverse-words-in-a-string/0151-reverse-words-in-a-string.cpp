class Solution {
public:
    string reverseWords(string s) {
        // Step 1: trim spaces
        int n = s.size();
        int i = 0, j = n - 1;
        while (i < n && s[i] == ' ') i++;
        while (j >= 0 && s[j] == ' ') j--;
        
        string trimmed = s.substr(i, j - i + 1);
        
        // Step 2: split words
        vector<string> words;
        stringstream ss(trimmed);
        string word;
        while (ss >> word) {
            words.push_back(word);
        }
        
        // Step 3: reverse words
        reverse(words.begin(), words.end());
        
        // Step 4: join words
        string result;
        for (int k = 0; k < words.size(); k++) {
            if (k > 0) result += " ";
            result += words[k];
        }
        return result;
    }
};
