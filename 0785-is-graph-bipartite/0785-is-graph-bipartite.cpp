class Solution {
public:
    bool res = false;
    bool dfs(vector<vector<int>>& graph,int node,int c ,vector<int>&colors){
        colors[node] = c;
        for(int j =0 ; j<graph[node].size() ;j ++){
            int neigh = graph[node][j];
            if(colors[neigh]!=-1 && colors[neigh]==c){
                return false;
            }
           if (colors[neigh] == -1) {
                if (!dfs(graph, neigh, 1 - c, colors)) {
                    return false;
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>colors(n,-1);
        for(int i = 0; i < n ; i++){
            if(colors[i]==-1){
                if (!dfs(graph, i, 0, colors)) {
                    return false;
                }
            }
        }
    return true;
    }
};