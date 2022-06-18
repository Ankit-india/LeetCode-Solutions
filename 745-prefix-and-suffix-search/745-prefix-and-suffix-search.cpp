class WordFilter {
public:
    unordered_map<string, int> mp;
    WordFilter(vector<string>& words) {
         for(int k = 0; k < words.size(); k++){
            string s = words[k];
            int n = s.size();
            for(int i = 1;i <= n; i++){
                string temp = s.substr(0,i);
                temp += '*';
                for(int j = 1; j <= n; j++){
                    string temp1 = "";
                    temp1 = s.substr(j - 1);
                    mp[temp + temp1] = k;
                }
            }
        }
    }
    
    int f(string prefix, string suffix) {
        string s = prefix;
        s += '*';
        s += suffix;
        return mp.count(s) ? mp[s] : -1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */