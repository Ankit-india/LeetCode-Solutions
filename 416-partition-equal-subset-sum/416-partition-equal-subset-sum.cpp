class Solution {
public:
    bool solve(vector<int>& arr, int sum){
        int n = arr.size();
        vector<vector<bool>> dp(n + 1, vector<bool> (sum + 1));
        
        for(int i = 0; i < n+1; i++){
            for(int j = 0; j < sum+1; j++){
                if(i == 0){
                    dp[i][j] = false;
                }
                if(j == 0){
                    dp[i][j] = true;
                }
            }
            
        }
        
        for(int i = 1; i < n+1; i++){
            for(int j = 1; j < sum+1; j++){
                if(arr[i-1] <= j){
                    dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i -1][j];
                }
            }
        }
        return dp[n][sum];
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto x: nums) sum += x;
        if(sum % 2 == 1) return false;
        
        return solve(nums, sum / 2);
        
    }
};