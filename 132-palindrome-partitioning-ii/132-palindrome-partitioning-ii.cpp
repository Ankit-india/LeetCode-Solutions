class Solution {
    bool checkPalindrome(int i, int j, string& str){
        while(i < j){
            if(str[i] != str[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    
    int fun(int i, int n, string& str, vector<int>& dp){
        if(i == n) return 0;
        
        
        if(dp[i] != -1) return dp[i];
        int ans = INT_MAX;
        
        for(int j = i; j < n; j++){
            if(checkPalindrome(i,j,str)){
                int cost = 1 + fun(j + 1, n, str, dp);
                ans = min(ans, cost);
            }
        }
        return dp[i] = ans;
    }
public:
    int minCut(string s) {
        // vector<int> dp(s.size(), -1);
        int n = s.size();
        vector<int> dp(n+1, 0);
        dp[n] = 0;
        
        for(int i = n -1; i >= 0; i--){
            int ans = INT_MAX;
        
            for(int j = i; j < n; j++){
                if(checkPalindrome(i,j,s)){
                    int cost = 1 + dp[j+1];
                    ans = min(ans, cost);
                }
            }
            dp[i] = ans;
        }
        return dp[0] - 1;
    }
};