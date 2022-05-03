class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int cnt[201] = {}, freq[201] = {}, res = 0;
        for (int j = 0; j < nums.size(); j++) {
            unordered_set<int> s;
            for (int i = 0; i + j < nums.size(); i++) {
                cnt[i] += nums[i + j] % p == 0;
                if (cnt[i] <= k) {
                    freq[i] = ((long long)freq[i] * 200 + nums[i + j]) % 1000000007;
                    res += s.insert(freq[i]).second;
                }
            }
        }
        return res;
    }
};