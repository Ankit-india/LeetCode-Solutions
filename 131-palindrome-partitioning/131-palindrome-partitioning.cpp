class Solution {
public:
    bool checkPalindrome(string &s, int i, int j){
        while(i <= j){
            if(s[i] != s[j]){
                return 0;
            }
            i++;
            j--;
        }
        return 1;
    }
    
    void solve(string &s, int i, int n, vector<string> tAns, vector<vector<string>>& ans){
        if(i >= n){
            ans.push_back(tAns);
            return;
        }
    
        for(int z = i; z < n; z++){
            if(checkPalindrome(s, i, z)){
                tAns.push_back(s.substr(i, z-i+1));
                solve(s, z+1, n, tAns, ans);
                tAns.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        solve(s,0,s.size(),{},ans);
        return ans;
    }
};