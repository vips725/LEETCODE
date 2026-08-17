class Solution {
public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,1,-1};

    bool valid(int i, int j , int n , int m){
        return !(i<0 || i>=n || j<0 || j>=m);
    }

    void dfs(vector<vector<char>>& grid , int i , int j , int n , int m , vector<vector<int>>& vis){
        vis[i][j] = 1;
        for(int k =0 ; k < 4; k++){
            int row = i + dx[k];
            int col = j + dy[k];
            if(valid(row,col,n,m) && grid[row][col]=='1' && vis[row][col]==0){
                dfs(grid,row,col,n,m,vis);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int res = 0;
        vector<vector<int>> vis(n, vector<int>(m,0));

        for(int i =0 ; i< n ; i++){
            for(int j =0 ; j<m; j++){
                if(grid[i][j]=='1' && vis[i][j]==0){
                    dfs(grid,i,j,n,m,vis);
                    res++;
                }
            }
        }
        return res;
    }
};
