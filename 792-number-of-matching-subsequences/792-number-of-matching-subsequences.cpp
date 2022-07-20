class Solution {
    
//     string lcs(string x, string y, int m, int n){
//         int dp[m+1][n+1];
//         memset(dp,0,sizeof(dp));
        
//         for(int i = 1; i <= m; i++){
//             for(int j = 1; j <= n; j++){
//                 if(x[i-1] == y[j-1]){
//                     dp[i][j] = 1 + dp[i-1][j-1];
//                 }
//                 else{
//                     dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
//                 }
//             }
//         }
//         int i = m, j = n;
//         string s = "";
//         while(i > 0 && j > 0){
//             if(x[i-1] == y[j-1]){
//                 s += x[i-1];
//                 i--;
//                 j--;
//             }
//             else{
//                 if(dp[i][j-1] < dp[i-1][j]){
//                     i--;
//                 }
//                 else{
//                     j--;
//                 }
//             }
//         }
//         reverse(s.begin(), s.end());
//         // cout << s << endl;
//         return s;
//     }
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>>trace(26);
        for(int i = 0; i < s.size(); i++){
            trace[s[i]-'a'].push_back(i);
        }
        
        int ans = 0; 
        
        for(auto x: words){
            int lastIdx = -1;
            bool isSubSeq = true;
            for(auto it : x){
                auto temp = upper_bound(trace[it - 'a'].begin(), trace[it -'a'].end(), lastIdx);
                if(temp == trace[it-'a'].end()){
                    isSubSeq = false;
                    break;
                }
                else{
                    lastIdx = *temp;
                }
            }
            if(isSubSeq){
                ans++;
            }
        }
        return ans;
        
    }
};