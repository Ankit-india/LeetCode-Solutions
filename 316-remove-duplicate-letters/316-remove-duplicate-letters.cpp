class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> freq(26,0) , occ(26,0);
        
        string ans = "";
        int n = s.size();
        
        for(int i = 0; i<n; ++i){
            freq[s[i] - 'a']++;
        }
        for(int i = 0; i<n; ++i)
        {
            freq[s[i] - 'a']--;
            if(!occ[s[i]- 'a'])
            {
                while((ans.size() > 0) && (ans.back() > s[i]) && (freq[ans.back() - 'a'] > 0))
                {
                    occ[ans.back() - 'a'] = 0;
                    ans.pop_back();
                }
                
                ans += s[i];
                occ[s[i] - 'a'] = 1;
            }
        }
        return ans;
    }
};