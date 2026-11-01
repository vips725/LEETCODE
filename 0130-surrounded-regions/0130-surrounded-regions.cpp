class Solution {
public:

    bool valid(int i, int j, int n, int m){
    return i >= 0 && j >= 0 && i < n && j < m;
}

    int x[4] = {1,-1,0,0};
    int y[4] = {0,0,1,-1};

    void dfs(vector<vector<char>>&board , int n,  int m ,int i , int j){
        board[i][j]='#';
        for(int k = 0 ; k <4;k++){
            int row = i+x[k];
            int col = j+y[k];
             if(valid(row, col, n, m) && board[row][col] == 'O'){
                dfs(board,n,m,row,col);
            }
        }
        return;
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        int i , j;
        for(j =0 ; j < m; j++){
            if(board[0][j]=='O'){
                dfs(board,n,m,0,j);
            }
        }
         for(j =0 ; j < m; j++){
            if(board[n-1][j]=='O'){
                dfs(board,n,m,n-1,j);
            }
        }
         for(i =0 ; i < n; i++){
            if(board[i][0]=='O'){
                dfs(board,n,m,i,0);
            }
        }
         for(i =0 ; i < n; i++){
            if(board[i][m-1]=='O'){
                dfs(board,n,m,i,m-1);
            }
        }
        for(int i = 0 ; i < n ; i ++){
            for(int j = 0 ; j < m ; j++){
                if(board[i][j]=='#'){
                    board[i][j]='O';
                }else{
                    board[i][j]='X';
                }
            }
        }
        return ;
    }
};