class Solution {
public:
    string decodeMessage(string key, string message) {
        // cout << key << endl/;
        unordered_map<char, char>mp;
        char a = 'a';
        for(int i = 0; i < key.size(); i++){
            if(key[i] != ' ' && mp.find(key[i]) == mp.end()){
                mp[key[i]] = a;
                a++;
                // cout << a << endl;
            }
        }
        // for(auto x: mp){
        //     cout << x.first << " -> "  << x.second << endl;
        // }
        string ans = "";
        for(auto x: message){
            if(x == ' '){
                ans += ' ';
            }
            else{
                ans += mp[x];
            }
        }
        return ans;
    }
};