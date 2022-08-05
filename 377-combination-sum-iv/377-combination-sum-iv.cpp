class Solution {
    int helperFun(vector<int>& nums, int target) {
        if(target == 0) return 1;
        else if(target < 0) return 0;
        int ans = 0;
        for(auto x : nums){
            ans += helperFun(nums, target - x);
        }
        return ans;
    }
    int mem(vector<int>& nums, int target, vector<int>& dp) {
        if(target == 0) return 1;
        else if(target < 0) return 0;
        if(dp[target] != -1) return dp[target];
        int ans = 0;
        for(auto x : nums){
            ans += mem(nums, target - x, dp);
        }
        return dp[target] = ans;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        // return helperFun(nums, target);
        vector<int> dp(target+1, -1);
        return mem(nums, target, dp);
    }
};