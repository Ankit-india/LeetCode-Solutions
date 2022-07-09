class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<int> dp(n,0);
        map<int,int> mp;
        int maxi = nums[0];
        dp[0] =  nums[0];
        mp[dp[0]]++;
        int i;
        for(i = 1; i<min(n,k+1); i++){
            dp[i] = maxi+nums[i];
            mp[dp[i]]++;
            maxi = max(maxi,dp[i]);
        }
        for(; i<n; i++){
                if (mp[dp[i-k-1]]==1){
                    mp.erase(dp[i-k-1]);
                }
                else{
                    mp[dp[i-k-1]]--;
                }
            
                maxi = mp.crbegin()->first;
                dp[i] = nums[i]+maxi;

                mp[dp[i]]++;
        }
       
        return dp[n-1];
    }
};