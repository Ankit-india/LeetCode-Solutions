class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> ump;
        for(auto x : s){
            ump[x]++;
        }
        int ans = 0, temp = 0;
        for(auto it: ump){
            if(it.second & 1){
                ans += it.second-1;
                temp = 1;
            }
            else{
                ans += it.second;
            }
        }
        if(temp) return ans +1;
        return ans;

    }
};