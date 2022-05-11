class Solution {
public:
    string lcs(string x, string y, int m, int n){
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
        int i = m, j = n;
        string s = "";
        while(i > 0 && j > 0){
            if(x[i-1] == y[j-1]){
                s+=x[i-1];
                i--;
                j--;
            }
            else{
                if(dp[i][j-1] > dp[i-1][j]){
                    j--;
                }
                else{
                    i--;
                }
            }
        }
        reverse(s.begin(), s.end());
        return s;
    }
    bool isSubsequence(string s, string t) {
        string subseq = lcs(s,t,s.size(), t.size());
        cout << subseq;
        if(subseq == s){
            return true;
        }
        return false;
    }
};