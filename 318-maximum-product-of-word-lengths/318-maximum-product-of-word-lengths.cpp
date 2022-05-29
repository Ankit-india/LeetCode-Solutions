class Solution {
public:
    int maxProduct(vector<string>& words) {
        int ans = 0;
        int n = words.size();
        vector<int> m(n,0);
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < words[i].size(); j++){
                m[i] |= (1 << (words[i][j] - 'a'));
            }
        }
        
        for(int i = 0; i < n; i++){
            int tp1 = words[i].size();
            for(int j = i + 1; j < n; j++){
                int tp2 = words[j].size();
                if((m[i] & m[j]) == 0){
                    ans = max(ans, tp1 * tp2);
                }
            }
        }
        return ans;
    }
};