class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls=0;
        int cows=0;
        int n = secret.length();
        map<int, int> cws;
        map<int, int> posCow;
        for(int i=0;i<n;i++) {
            if(secret[i] == guess[i]) bulls++;
            else {
                posCow[i] = secret[i];
                cws[guess[i]]++;
            }
        }
        
        for(auto a : posCow) {
            if(cws[a.second] > 0) {
                cows++;
                cws[a.second]--;
            }
        }
        string ans = "" + to_string(bulls) + "A" + to_string(cows) + "B";
        return ans;
    }
};