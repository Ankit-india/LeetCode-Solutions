class Solution {
    unordered_map<char, vector<char> >mp;
    int mod = 1e9+7;
    
    int solve(int n, int i, char prev, vector<vector<long long>>& dp){
        if(i > n) return 0;
        
        if( i == n) {
            switch(prev){
                case 'a':
                    return 1;
                case 'e':
                    return 2;
                case 'i':
                    return 4;
                case 'o':
                    return 2;
                case 'u':
                    return 1;
                default:
                    return 5;
            }
        }
        int idx = prev - 'a';
        if(dp[i][idx] != -1) return dp[i][idx];
        
        long long ans = 0;
        for(auto x: mp[prev]){
            ans += (solve(n, i+1, x, dp) % mod);
        }
        return dp[i][idx] = ans % mod;
    }
public:
    int countVowelPermutation(int n) {
        if(n==1) return 5;
        mp['a'] = {'e'};
        mp['e'] = {'a','i'};
        mp['i'] = {'a', 'e', 'o', 'u'};
        mp['b'] = {'a', 'e', 'i','o', 'u'};
        mp['o'] = {'i','u'};
        mp['u'] = {'a'};
        vector<vector<long long>> dp(vector<vector<long long>> (n+2, vector<long long>(27,-1)));
        return solve(n, 1, 'b', dp);
    }
};