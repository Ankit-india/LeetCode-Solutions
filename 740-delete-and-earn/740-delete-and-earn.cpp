class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n1 = 0, n2 = 0;
        
        const int n = 10001;
        vector<int> dp(n,0);
        
        for(auto x: nums){
            dp[x] += x;
        }
        // for(auto x: dp){
//             cout << x << " ";
//         }
        
        for(int i = 0; i < n; i++){
            // int temp1 = n2 + (dp[i] * i);
            int temp1 = n2 + dp[i]; 
            int temp2 = max(n1,n2);
            n1 = temp1;
            n2 = temp2;   
        }
        return max(n1,n2);
        
        
    }
};