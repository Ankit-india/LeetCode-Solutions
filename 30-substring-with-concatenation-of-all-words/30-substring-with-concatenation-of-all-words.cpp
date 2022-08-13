class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = words[0].length();
        int numberOfWords = words.size();
        if(n * numberOfWords > s.size()){
            return {};
        }
        unordered_map<string, int> mp;
        for(auto x: words){
            mp[x]++;
        }
        vector<int>ans;
        for(int i = 0; i <= s.size() - (numberOfWords * n); i++){
            unordered_map<string, int> temp;
            for(int j = i; j < i + (numberOfWords * n); j += n){
                string curr = s.substr(j, n);
                if(mp.find(curr) == mp.end()){
                    break;
                }
                temp[curr]++;
                if(temp[curr] > mp[curr]){
                    break;
                }
                
            }
            if(mp == temp){
                ans.push_back(i);
            }
        }
        return ans;
    }
};