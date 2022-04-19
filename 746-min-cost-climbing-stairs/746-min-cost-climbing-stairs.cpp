class Solution {
public:
    int minCostClimbingStair(int n, vector<int>& cost, vector<int>& dp) {
        if(n <= 1) return dp[n] = cost[n];
        
        if(dp[n] != -1){
            return dp[n];
        }
        
        return dp[n] = min(minCostClimbingStair(n-1, cost, dp), minCostClimbingStair(n-2, cost, dp)) + cost[n];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        cost.push_back(0);
        vector<int> dp(cost.size() + 1, -1);
        
        return minCostClimbingStair(cost.size()-1, cost, dp);
        
    }
};