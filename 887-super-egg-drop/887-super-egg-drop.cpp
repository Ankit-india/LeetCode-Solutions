class Solution {
public:
    int solve(int e, int f, vector<vector<int>>& dp){
        if(f == 1 || f == 0 || e == 1){
            return f;
        }
        if(dp[e][f] != -1){
            return dp[e][f];
        }
        int ans = INT_MAX;
        int i = 1; 
        int j = f;
        while(i <= j){
            
            // int temp = 1 + max(solve(e-1, i-1, dp), solve(e, f-i, dp));
            int mid = (i + j) / 2;
            
            int temp1 = 0;
            if(dp[e-1][mid-1] != -1) {
                temp1 = dp[e-1][mid-1];
            }
            else {
                temp1 = solve(e - 1, mid - 1, dp);
                dp[e-1][mid-1] = temp1;
            }
            int temp2 = 0;
            if(dp[e][f - mid] != -1) {
                temp2 = dp[e][f - mid];
            }
            else {
                temp2 = solve(e, f - mid, dp);
                dp[e][f - mid] = temp2;
            }
            if(temp1 < temp2){
               i = mid + 1;
            }
            else{
               j = mid - 1;
            }
            int temp = 1 + max(temp1, temp2);
            ans = min(ans, temp);
        }
        return dp[e][f] = ans;
    }
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(k+1, vector<int> (n+1, -1));
        
        
        return solve(k, n, dp);
    }
};