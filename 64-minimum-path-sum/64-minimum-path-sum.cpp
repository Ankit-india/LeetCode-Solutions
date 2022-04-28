class Solution {
public:
    int helper(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(i == 0 && j == 0){
            return grid[i][j];
        }
        if(i < 0 || j < 0){
            return 1e9;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int up = grid[i][j] + helper(i-1, j, grid, dp);
        int left = grid[i][j] + helper(i, j-1, grid, dp);
        return min(up,left);
    }
    int minPathSum(vector<vector<int>>& ht) {
        int n = ht.size();
        int m = ht[0].size();
        vector<vector<int>> dp(n, vector<int> (m,0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i == 0 && j == 0){
                    dp[i][j] = ht[i][j];
                }
                else{
                    int up = ht[i][j];
                    if(i > 0){
                        up += dp[i-1][j];
                    }
                    else {
                        up += 1e9;
                    }
                    int left = ht[i][j];
                    if(j > 0){
                        left += dp[i][j-1];
                    }
                    else{
                        left += 1e9;
                    }
                    dp[i][j] = min(up, left);
                }
            }
        }
        return dp[n-1][m-1];
    }
};