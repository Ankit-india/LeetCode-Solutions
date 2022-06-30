class Solution {
    private:
      void dfs(vector<vector<char>>& board,int i,int j)
      {
          if(board[i][j]=='O') { 
              board[i][j]='A';
            if(i+1<board.size()){ 
                dfs(board,i+1,j);
            }
            if(i>1) {
                dfs(board,i-1,j);
            }
            if(j+1<board[i].size()) {
                dfs(board,i,j+1);
            }
            if(j>1) {
                dfs(board,i,j-1);
            }
        }
      }
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        
        if(n==0) return;
        for(int i=0;i<n;i++)
        {
            dfs(board,i,0);
            dfs(board,i,m-1);
        }
        for(int j=0;j<m-1;j++)
        {
            dfs(board,0,j);
            dfs(board,n-1,j);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='O') {
                    board[i][j]='X';
                }
                else if(board[i][j]=='A') {
                    board[i][j]='O';
                }
                
            }
        }
    }
};
//     void dfs(vector<vector<char>>& board, int x, int y, int row, int col){
//         if(x < 0 || x >= row || y < 0 || y >= col || board[x][y] != 'O') {
//             return;
//         }
//         board[x][y] = 'X';
        
//         dfs(board, x, y+1, row, col);
//         dfs(board, x, y-1, row, col);
//         dfs(board, x+1, y, row, col);
//         dfs(board, x-1, y, row, col);
//     }
// public:
//     void solve(vector<vector<char>>& board) {
//         int rw = board.size();
//         if(rw == 0) return;
        
//         int cl = board[0].size();
        
//         for(int i = 1; i < rw-1; i++){
//             for(int j = 1; j < cl-1; j++){
//                 if(board[i][j] == 'O'){
//                     dfs(board, i,j, rw, cl);
//                 }
//             }
//         }
//     }
// };