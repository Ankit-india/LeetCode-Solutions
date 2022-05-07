// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int minDeletions(string str, int n);

int main(){
    int t;
    cin >> t;
    while(t--){
        
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << minDeletions(s, n) << endl;

    }
return 0;
}// } Driver Code Ends

int lcs(string x, string y, int m, int n){
    int dp[m+1][n+1];
    memset(dp,0,sizeof(dp));
    
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(x[i-1] == y[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[m][n];
}
int minDeletions(string s, int n) { 
    //complete the function here 
    string t = s;
    reverse(t.begin(), t.end());
    
    return s.size() - lcs(s,t,n, n);
} 