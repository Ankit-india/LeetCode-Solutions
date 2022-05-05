// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    // memoization
    // int dp[1001][1001];
    // int lcs(string x, string y, int n, int m){
    //     if(m == 0 || n == 0){
    //         return 0;
    //     }
    //     if(dp[n][m] != -1){
    //         return dp[n][m];
    //     }
    //     if(x[n-1] == y[m-1]){
    //         return dp[n][m] = 1 + lcs(x,y,n-1, m-1);
    //     }
    //     else{
    //         return dp[n][m] = max(lcs(x,y,n-1,m), lcs(x,y,n,m-1));
    //     }
    // }
    // Tabulation
    int longestCommonSubstr (string x, string y, int n, int m)
    {
        // your code here
        
        
        int dp[n+1][m+1];
        int ans = 0;
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= m; j++){
                if(i == 0 || j == 0){
                    dp[i][j] = 0;
                }
                
            }
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(x[i-1] == y[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1]; 
                    ans = max(ans, dp[i][j]);
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }
        
        // for(int i = 0;  i <= n; i++){
        //     for(int  j = 0; j <= m; j++){
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << dp[n][m] << endl;
        return ans;
    
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends