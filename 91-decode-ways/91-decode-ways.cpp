class Solution {
public:
    int foo(int idx, string s, vector<int>& dp){
        if(idx >= s.size()){
            return 1;
        }
        
        int ans = 0;
        int oneDig = s[idx] - '0', twoDig = 0;
        if(idx < s.size() - 1){
            twoDig = oneDig * 10 + s[idx+1] - '0';
        }
        if(dp[idx] != -1){
            return dp[idx];
        }
        if(oneDig > 0) {
            ans += foo(idx+1, s, dp);
        }
        if(oneDig > 0 && twoDig > 0 && twoDig < 27){
            ans += foo(idx+2, s, dp);
        }
        return dp[idx] = ans;
    }
    int numDecodings(string s) {
        vector<int>dp(s.size() + 1, -1);
        return foo(0, s, dp);
    }
};