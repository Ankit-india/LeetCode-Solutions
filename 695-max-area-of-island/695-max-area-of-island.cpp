class Solution {
public:
    int maxArea(vector<vector<int>>& g , int i , int j , int r , int c)
    {
        if(i < 0|| j < 0|| i == r|| j == c|| g[i][j] == 0|| g[i][j] == 2){
            return 0;
        }
        g[i][j]=2;
        int res = 1 + maxArea(g, i,j-1, r, c);
        res += maxArea(g, i, j+1, r, c);
        res += maxArea(g, i-1, j, r, c);
        res += maxArea(g, i+1, j, r, c);
        return res;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size(), ans = 0;
        for(int i = 0; i < r; i++){
            for(int j=0;j<c;j++){
                ans = max(ans, maxArea(grid,i,j,r,c));
            }
        }
        return ans;
    }
};