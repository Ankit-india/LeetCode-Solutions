class Solution {
    int uf[26];
    int find(int x) {
        return uf[x] == x ? x : (uf[x] = find(uf[x]));
    }
public:
    bool equationsPossible(vector<string>& equations) {
        for (int i = 0; i < 26; ++i) {
            uf[i] = i;
        }
        for (auto x : equations) {
            if (x[1] == '='){
                uf[find(x[0] - 'a')] = find(x[3] - 'a');
            } 
        }
        for (auto x : equations) {
            if (x[1] == '!' && find(x[0] - 'a') == find(x[3] - 'a')){
                return false;
            }
        }
        return true;
    }
};