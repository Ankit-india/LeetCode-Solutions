// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isPalindromic(string s, int i ,int j){
        if(i >= j) return true;
        while(i < j){
            if(s[i] != s[j]){
                return false;
            }
            i++; 
            j--;
        }
        return true;
    }
    
    int solve(string s, int i, int j, vector<vector<int>>& dp){
        if(i >= j) return 0;
        if(isPalindromic(s,i,j) == true) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = INT_MAX;
        for(int k = i; k < j; k++){
            // int temp = solve(s, i, k, dp) + solve(s, k+1, j, dp) + 1;
            int temp1 = 0;
            if(dp[i][k] != -1){
                temp1 = dp[i][k];
            }
            else{
                temp1 = solve(s,i,k,dp);
                dp[i][k] = temp1;
            }
            int temp2 = 0;
            if(dp[k+1][j] != -1){
                temp2 = dp[k+1][j];
            }
            else{
                temp2 = solve(s,k+1, j, dp);
                dp[k+1][j] = temp2;
            }
            int temp = temp1 + temp2 + 1;
            ans = min(ans, temp);
        }
        return dp[i][j] = ans;
    }
    int palindromicPartition(string str)
    {
        // code here
        vector<vector<int>> dp(501, vector<int>(501, -1));
        return solve(str, 0, str.size() - 1,dp);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends