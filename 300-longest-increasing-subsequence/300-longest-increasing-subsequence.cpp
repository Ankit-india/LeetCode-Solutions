class Solution {
    int lis(int n, vector<int>& arr, vector<int>& dp){
        if(dp[n] != -1) return dp[n];
        int ans = 1;
        for(int i = 0; i < n; i++){
            if(arr[i] < arr[n]) ans = max(ans, lis(i, arr,dp)+1);
        }
        return dp[n] = ans;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int res = 0;
        vector<int> dp(nums.size(), -1);
        for(int i = 0; i < nums.size(); i++){
            res = max(res, lis(i, nums, dp));
        }
        return res;
    }
};