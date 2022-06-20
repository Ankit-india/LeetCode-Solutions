class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        for(int i=0;i<words.size();i++){
            words[i]=string(words[i].rbegin(), words[i].rend());
        }
        sort(words.begin(), words.end());
        int ans = words.back().length() + 1;
        for(int i = words.size() - 2; i >= 0; i--){
            if(words[i+1].substr(0, words[i].length()) == words[i]) continue;
            else ans+=words[i].length()+1;
        }
        return ans;
    }
};