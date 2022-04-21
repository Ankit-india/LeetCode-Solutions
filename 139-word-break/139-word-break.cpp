class Solution {
public:
    // unordered_map<string, bool> dp;
    bool wordBreak(string s, vector<string>& wordDict) {
        // int n = s.size();
        // if(n == 0){
        //     return true;
        // }
        // if(dp[s] != false){
        //     return dp[s];
        // }
        // for(int i = 1; i <= n; i++){
        //     int temp = 0;
        //     string str = s.substr(0,i);
        //     for(int j = 0; j < wordDict.size(); j++){
        //         if(str.compare(wordDict[j]) == 0){
        //             temp = 1;
        //             break;
        //         }
        //     }
        //     if(temp == 1 && wordBreak(s.substr(i,n-i), wordDict) == true){
        //         return dp[s] = true;
        //     }
        // }
        // return dp[s] = false;
        int n = s.size();
        vector<bool>dp(n+1, false);
        dp[n] = true;
        
        for(int i = n-1; i >=0; i--) {
            for(int j = n; j > i; j--) {
                if(dp[j] == true) {
                    string temp = s.substr(i, (j-i));
                    //cout << i << " " << j << " " << temp <<endl;
                    if(find(wordDict.begin(), wordDict.end(), temp) != wordDict.end()) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        
        return dp[0];
    }
};