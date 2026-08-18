class Solution {
public:
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};

    bool valid(int i , int j , int n , int m){
        return !(i<0 || i>=n || j<0 || j>=m);
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int fresh = 0;
        int time = 0;
        queue<pair<int,int>> q;

        // Step 1: collect rotten oranges + count fresh
        for(int i =0 ; i < n ; i++){
            for(int j =0 ; j < m ; j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                } else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }

        // Step 2: BFS spread
        while(!q.empty() && fresh>0){
            time++;
            int s = q.size();
            while(s--){
                auto [r,c] = q.front();
                q.pop();
                for(int k = 0 ; k<4; k++){
                    int row = r + dx[k];
                    int col = c + dy[k];
                    if(valid(row,col,n,m) && grid[row][col]==1){
                        q.push({row,col});
                        grid[row][col] = 2; 
                        fresh--;
                    }
                }
            }
        }

        return fresh>0 ? -1 : time;
    }
};
