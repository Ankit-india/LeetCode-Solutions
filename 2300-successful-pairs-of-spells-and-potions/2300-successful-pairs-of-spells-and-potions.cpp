class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        
        sort(potions.begin(),potions.end());
        vector<int> ans;
        for(int i = 0; i < spells.size(); i++)
        {
            long long k = ceil (double(success * 1.0 / spells[i]));

            auto temp = lower_bound(potions.begin(), potions.end(), k);
            ans.push_back(potions.size() - (temp - potions.begin()));
        }
        return ans;
        
        // vector<int> ans;
        // int dp[100001];
        // memset(dp, 0, sizeof(dp));
        // sort(potions.begin(), potions.end());
        // for(int i = 0; i < spells.size(); i++){
        //     int count = 0;
        //     if(dp[spells[i]] == 0){
        //         for(int j =  potions.size() - 1; j >= 0; j--){
        //             long long int temp = (long long) spells[i] * (long long)potions[j]; 
        //             if(temp >= success){
        //                 count++;
        //             }
        //             else break;
        //         }    
        //     }
        //     if(dp[spells[i]] != 0){
        //         ans.push_back(dp[spells[i]]);
        //     }
        //     else {
        //         ans.push_back(count);
        //     }
        //     dp[spells[i]] = count;    
        // }
        // return ans;
    }
};