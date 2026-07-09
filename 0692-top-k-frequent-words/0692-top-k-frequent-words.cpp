class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> freq;
        for(string &w : words) freq[w]++;

        auto cmp = [](const pair<string,int>& a, const pair<string,int>& b) {
            if(a.second == b.second) return a.first > b.first; // lexicographical order
            return a.second < b.second; // higher freq first
        };

        priority_queue<pair<string,int>, vector<pair<string,int>>, decltype(cmp)> pq(cmp);

        for(auto &p : freq) {
            pq.push({p.first, p.second});
        }

        vector<string> result;
        while(k-- && !pq.empty()) {
            result.push_back(pq.top().first);
            pq.pop();
        }
        return result;
    }
};
