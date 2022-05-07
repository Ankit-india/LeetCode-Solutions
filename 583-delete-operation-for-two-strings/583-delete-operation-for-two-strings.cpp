class Solution {
public:
    int lcs(string x, string y, int m, int n){
        int dp[m+1][n+1];
        memset(dp,0,sizeof(dp));
        
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(x[i-1] == y[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
    int minDistance(string x, string y) {
        if(x == y) return 0;
        int m = x.size();
        int n = y.size();
        int ct = lcs(x,y,m,n);
        
        return m + n - 2 * ct;
    }
};