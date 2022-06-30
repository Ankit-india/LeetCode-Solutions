class Solution {
public:
    void dfs(vector<vector<char>>& grid, int x, int y, int r, int c){
        
        if(x<0 || x >= r || y<0 || y >= c || grid[x][y] != '1') return;
        
        grid[x][y] = '2';
        
        dfs(grid, x, y+1, r, c);
        dfs(grid, x, y-1, r, c);
        dfs(grid, x+1, y, r, c);
        dfs(grid, x-1, y, r, c);
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if(m == 0) return 0;
        int n = grid[0].size();
        
        int ans = 0;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){
                    dfs(grid, i, j, m, n);
                    ans++;
                }
            }
        }
        return ans;        
    }
};