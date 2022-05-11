// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		int LongestRepeatingSubsequence(string str){
		    // Code here
		    string x = str, y = str;
		    int m = x.size(), n = y.size();
		    
		    int dp[m+1][n+1];
		    memset(dp,0,sizeof(dp));
		    
		    for(int i = 1; i <= m; i++){
		        for(int j = 1; j <= n; j++){
		            if(x[i-1] == y[j-1] && i != j){
		                dp[i][j] = 1 + dp[i-1][j-1]; 
		            }
		            else{
		                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		            }
		        }
		    }
		    
		    return dp[m][n];
		    
		}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends