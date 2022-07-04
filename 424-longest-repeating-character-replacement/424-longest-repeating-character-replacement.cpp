class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int len = 0;
        
        int i = 0;
        int j = 0;
        unordered_map<int,int> mp;
        int maxFreq = 0;
        
        while(i < n){
            mp[s[i]]++;
            maxFreq = max(maxFreq, mp[s[i]]);
            
            int currWindowSize = i - j + 1;
            
            if(currWindowSize - maxFreq > k){
                mp[s[j]]--;
                j++;
            }
            
            len = max(len, i - j + 1);
            i++;
        }
        
        return len;
    }
};