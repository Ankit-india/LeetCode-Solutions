class Solution {
public:
    
    int func(int ind, vector<int>&nums, int target,vector<vector<int>>&dp){
         int a = sqrt(target);
        if(a * a == target) return 1;
        if(target <= 3) return target;
        
        if(target == 0 )return 0;
        
        if(ind >= nums.size()) return 1e7;
    
        if(dp[ind][target] != -1) return dp[ind][target];
        
        int nottake = func(ind+1, nums, target, dp);
        
        int take = 1e7;
        
        if(nums[ind] <= target)
            take = 1 + func(ind, nums, target - nums[ind], dp);
        
        return dp[ind][target] = min(take,nottake);
        
    }
    
    
    int numSquares(int n) {
        // int ans = INT_MAX;
        int dp[n+1];
        memset(dp,0,sizeof(dp));
        for(int i = 1; i <= n; i++){
            dp[i] = i;
            for(int j = 1; (j * j) <= i; j++){
                dp[i] = min(dp[i], 1 + dp[i-(j*j)]);
            }
        }
        return dp[n];
    }
};