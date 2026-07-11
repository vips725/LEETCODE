class UnionFind {
public:
    UnionFind(int n) : id(n), rank(n), nodeCount(n, 1), edgeCount(n) {
        iota(id.begin(), id.end(), 0);
    }
    int find(int u) { return id[u] == u ? u : id[u] = find(id[u]); }
    void unionByRank(int u, int v) {
        int i = find(u), j = find(v);
        ++edgeCount[i];
        if (i == j) return;
        if (rank[i] < rank[j]) {
            id[i] = j;
            edgeCount[j] += edgeCount[i];
            nodeCount[j] += nodeCount[i];
        } else if (rank[i] > rank[j]) {
            id[j] = i;
            edgeCount[i] += edgeCount[j];
            nodeCount[i] += nodeCount[j];
        } else {
            id[i] = j;
            edgeCount[j] += edgeCount[i];
            nodeCount[j] += nodeCount[i];
            ++rank[j];
        }
    }
    bool isComplete(int u) {
        return nodeCount[u] * (nodeCount[u] - 1) / 2 == edgeCount[u];
    }
private:
    vector<int> id, rank, nodeCount, edgeCount;
};

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int ans = 0;
        UnionFind uf(n);
        unordered_set<int> parents;
        for (auto& edge : edges) uf.unionByRank(edge[0], edge[1]);
        for (int i = 0; i < n; ++i) {
            int parent = uf.find(i);
            if (parents.insert(parent).second && uf.isComplete(parent)) ++ans;
        }
        return ans;
    }
};
