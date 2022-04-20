class Solution {
public:
    bool divisorGame(int n) {
        if(n==1) return false;
        vector<bool> dp(n+1,false);
        
        for(int i = 2; i <= n; i++) {
            int sq = sqrt(i);
            for(int j = 1; j <= sq; j++) {
                if(i % j == 0 && dp[i - j] == false) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};