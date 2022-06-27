class Solution {
public:
    int countPath(int i, int j, int m, int n, vector<vector<int>>& dp){
        if(i == m-1 && j == n-1) return 1;
        if(i >= m || j >= n) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = countPath(i+1,j,m,n,dp) + countPath(i,j+1, m,n,dp);
    }
    int uniquePaths(int m, int n) {
        // vector<vector<int>> dp(m+1, vector<int>(n+1,-1));
        // return countPath(0,0,m,n,dp);
        int temp = m + n - 2;
        int temp2 = m-1;
        double ans = 1;
        for(int i = 1; i <= temp2; i++){
            ans = ans * (temp - temp2 + i)/ i;
        }
        return (int) ans;
    }
};