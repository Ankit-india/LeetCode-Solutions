class Solution {
public:
    int sMap[26], pMap[26];
    // int n = 26;
    // vector<int> sMap(n,0), 
    // vector<int> pMap(n,0);
    bool checkValid() {
        for(int i=0;i<26;i++)
            if(sMap[i]!=pMap[i]) return false;         
        return true;
    }
    
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        // Base case
        if(s.size() < p.size()) {
            return ans;    
        }
        
        // Logic
        
        int start = 0, end = 0 , k = p.size();
        // sMap = new int[26];
        // pMap = new int[26];
        for (char c : p) pMap[c-'a']++;
        while (end < s.size()) {
            char curr = s[end];
            sMap[curr-'a']++;
            if (end - start + 1 < k) {
                end++;
            } else {
                if (checkValid()) ans.push_back(start);
                sMap[s[start] - 'a']--;
                start++;
                end++;
            }
        }
        return ans;
    }
};