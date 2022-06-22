class Solution {
public:
    int dfs(vector<vector<int>>& grid,int i,int j)
    {

        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || !grid[i][j]){
            return 0;
        }
        int temp = grid[i][j];
        grid[i][j] = 0;
        int count = 0;
        int x[] = {-1,0,1,0};
        int y[] = {0,-1,0,1};
        for(int k = 0; k < 4; k++){
            count = max(count, dfs(grid, i + x[k], j + y[k]));
        }
        grid[i][j] = temp;
        return count + temp;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]>0){
                   ans=max(ans,dfs(grid,i,j));
                }
            }
        }
        return ans;
    }
};