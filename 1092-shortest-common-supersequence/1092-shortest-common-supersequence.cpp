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
        // for(int i = 0; i <= m; i++){
        //     for(int  j = 0; j <= n; j++){
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        int i = m, j = n;
        string s = "";
        while(i > 0 && j > 0){
            if(x[i-1] == y[j-1]){
                s += x[i-1];
                i--;
                j--;
            }
            else{
                if(dp[i][j-1] > dp[i-1][j]){
                    s += y[j-1]; 
                    j--;
                }
                else{
                    s+= x[i-1];
                    i--;
                }
            }
        }
        while(i > 0){
            s+=x[i-1];
            i--;
        }
        while(j > 0){
            s+= y[j-1];
            j--;
        }
        reverse(s.begin(), s.end());
        return s;
    }
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.size();
        int n = str2.size();
        
        
        return  lcs(str1, str2, m,n);
    }
};