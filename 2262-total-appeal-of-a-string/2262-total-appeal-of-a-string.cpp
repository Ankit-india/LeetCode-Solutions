class Solution {
public:
    long long appealSum(string s) {
        long long res = 0, cur = 0, pre[26] = {};
        for (int i = 0; i < s.size(); i++) {
            cur += i + 1 - pre[s[i] - 'a'];
            pre[s[i] - 'a'] = i + 1;
            res += cur;
        }
        return res;
    }
};