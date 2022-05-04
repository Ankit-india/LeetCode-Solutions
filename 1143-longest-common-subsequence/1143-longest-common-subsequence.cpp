class Solution {
public:
       int lcs(string x, string y, int m, int n){
           vector<vector<int>>dp(m+1, vector<int>(n+1));
           
           for(int i = 0; i <= m; i++){
               for(int j = 0; j <= n; j++){
                   if(i == 0 || j == 0){
                       dp[i][j] = 0;
                   }
               }
           }
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
//     int lcs(string x, string y, int m, int n, vector<vector<int>>& dp){
//         if(m == 0 || n == 0){
//             return 0;
//         }
//         if(dp[m][n] != -1){
//             return dp[m][n];
//         }
        
//         if(x[m-1] == y[n-1]){
//             dp[m][n] = 1 + lcs(x,y,m-1,n-1,dp);
//         }
//         else{
//             dp[m][n] = max(lcs(x,y,m-1,n), lcs(x,y,m,n-1));
//         }
//         return dp[m][n];
//     }
//     int lcs(string x, string y, int m, int n){
//         if(m == 0 || n == 0){
//             return 0;
//         }
        
//         if(x[m-1] == y[n-1]){
//             return 1 + lcs(x,y,m-1,n-1);
//         }
//         return max(lcs(x,y,m-1,n), lcs(x,y,m,n-1));
//     }
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        int ans ;
        // recursive code;
        // ans = lcs(text1, text2, m, n);
        // Memoization
        // vector<vector<int>>dp(m+1, vector<int>((n+1), -1));
        // ans = lcs(text1, text2, m, n, dp);
        
        // tabulation
        ans = lcs(text1,text2,m,n);
        return ans;
    }
};